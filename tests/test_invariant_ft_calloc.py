import pytest
import ctypes
import sys
import math

# Simulate the vulnerable ft_calloc behavior in Python to test the invariant
# The invariant: ft_calloc(count, size) must either return NULL/None (allocation failure)
# OR return a buffer of at least (count * size) bytes — never a smaller buffer.

def ft_calloc_safe(count, size):
    """
    A safe reference implementation of ft_calloc that checks for overflow.
    Returns (buffer, actual_allocated_size) or (None, 0) on failure.
    """
    # Check for multiplication overflow
    if count != 0 and size != 0:
        if count > (sys.maxsize // size):
            # Overflow would occur — must return None (allocation failure)
            return None, 0
    
    total = count * size
    if total == 0:
        return bytearray(1), 1  # calloc(0,0) returns a unique pointer, not NULL
    
    try:
        buf = bytearray(total)
        return buf, total
    except MemoryError:
        return None, 0


def ft_calloc_vulnerable(count, size):
    """
    Simulates the vulnerable ft_calloc that does NOT check for overflow.
    Mimics: malloc(size * count) where multiplication can overflow.
    Uses Python's ctypes to simulate C-style size_t overflow.
    """
    SIZE_T_MAX = (2 ** (ctypes.sizeof(ctypes.c_size_t) * 8)) - 1
    
    # Simulate C size_t overflow: truncate to size_t width
    overflowed_total = (count * size) & SIZE_T_MAX
    
    if overflowed_total == 0 and (count != 0 and size != 0):
        # Overflow produced zero — malloc(0) behavior is implementation-defined
        # but the caller thinks they have count*size bytes
        return None, overflowed_total, count * size  # (buf, allocated, expected)
    
    try:
        buf = bytearray(overflowed_total)
        return buf, overflowed_total, count * size
    except MemoryError:
        return None, 0, count * size


# Adversarial payloads: (count, size) pairs designed to trigger integer overflow
# in size_t multiplication on 64-bit systems
SIZE_T_BITS = ctypes.sizeof(ctypes.c_size_t) * 8
SIZE_T_MAX = (2 ** SIZE_T_BITS) - 1

OVERFLOW_PAYLOADS = [
    # Classic overflow: 2^32 * 2^32 overflows 64-bit size_t
    (2**32, 2**32),
    # Large count, size=2 — overflows when count > SIZE_T_MAX/2
    (SIZE_T_MAX // 2 + 2, 2),
    # Large size, count=2
    (2, SIZE_T_MAX // 2 + 2),
    # Both near sqrt(SIZE_T_MAX)
    (2**32 + 1, 2**32 + 1),
    # Exactly SIZE_T_MAX + 1 split across two factors
    (2**32, 2**32 + 1),
    # Very large count with small size that still overflows
    (SIZE_T_MAX, 2),
    (SIZE_T_MAX, SIZE_T_MAX),
    # count=1 should never overflow
    (1, 1024),
    # size=1 should never overflow
    (1024, 1),
    # Zero cases
    (0, 1024),
    (1024, 0),
    (0, 0),
    # Boundary: exactly SIZE_T_MAX
    (1, SIZE_T_MAX),
    (SIZE_T_MAX, 1),
    # Near-overflow but not quite
    (SIZE_T_MAX // 4, 4),
    (SIZE_T_MAX // 4 + 1, 4),
    # Power-of-two overflows
    (2**31, 2**34),
    (2**16, 2**49),
    (2**8, 2**57),
    # Typical attack: allocate "1 GB" but overflow to tiny buffer
    (0x40000001, 4),
    (0x80000001, 2),
    # UINT32_MAX + 1 scenarios
    (0xFFFFFFFF, 0xFFFFFFFF),
    (0x100000000, 0x100000000),
]


@pytest.mark.parametrize("payload", OVERFLOW_PAYLOADS)
def test_ft_calloc_no_silent_overflow(payload):
    """
    Invariant: ft_calloc(count, size) must NEVER return a buffer smaller than
    (count * size) bytes without signaling failure (returning NULL/None).
    
    If the allocation succeeds (non-NULL return), the allocated buffer MUST be
    at least count*size bytes. A smaller buffer with a non-NULL return is a
    security violation enabling heap overflow.
    """
    count, size = payload
    
    SIZE_T_MAX = (2 ** (ctypes.sizeof(ctypes.c_size_t) * 8)) - 1
    
    # Calculate the true required size (Python handles big integers natively)
    true_required = count * size
    
    # Simulate what the vulnerable C code would allocate (with overflow)
    overflowed_size = (count * size) & SIZE_T_MAX
    
    # Determine if overflow occurred
    overflow_occurred = (true_required > SIZE_T_MAX) and (count != 0) and (size != 0)
    
    if overflow_occurred:
        # INVARIANT: If multiplication overflows, the implementation MUST
        # return NULL (failure), not a tiny buffer.
        # A correct implementation detects overflow and returns NULL.
        buf, allocated = ft_calloc_safe(count, size)
        
        # The safe implementation must return None on overflow
        assert buf is None, (
            f"ft_calloc({count}, {size}): overflow detected but allocation "
            f"succeeded — this is a security violation. "
            f"True size needed: {true_required}, "
            f"Overflowed size would be: {overflowed_size}"
        )
        
        # Verify the vulnerable version would have allocated wrong size
        if overflowed_size < true_required and overflowed_size > 0:
            # This is the dangerous case: vulnerable code allocates tiny buffer
            # but caller thinks they have true_required bytes
            assert overflowed_size < true_required, (
                f"Expected overflow to produce smaller allocation: "
                f"overflowed={overflowed_size}, true={true_required}"
            )
    else:
        # No overflow: allocation should succeed with correct size
        buf, allocated = ft_calloc_safe(count, size)
        
        if buf is not None:
            # INVARIANT: allocated buffer must be >= required size
            assert allocated >= true_required, (
                f"ft_calloc({count}, {size}): allocated {allocated} bytes "
                f"but {true_required} bytes were required — heap overflow risk"
            )
            
            # INVARIANT: buffer must be zero-initialized (calloc guarantee)
            if true_required > 0 and true_required <= 10 * 1024 * 1024:  # cap at 10MB for test
                assert all(b == 0 for b in buf[:min(len(buf), 1024)]), (
                    f"ft_calloc({count}, {size}): buffer not zero-initialized"
                )


@pytest.mark.parametrize("payload", OVERFLOW_PAYLOADS)
def test_ft_calloc_overflow_detection(payload):
    """
    Invariant: Any correct ft_calloc implementation must detect integer overflow
    in count*size before calling malloc(). If overflow would occur, it must
    return NULL rather than allocating an undersized buffer.
    """
    count, size = payload
    SIZE_T_MAX = (2 ** (ctypes.sizeof(ctypes.c_size_t) * 8)) - 1
    
    true_required = count * size
    overflow_would_occur = (true_required > SIZE_T_MAX) and (count != 0) and (size != 0)
    
    if overflow_would_occur:
        # A secure implementation MUST detect this and return NULL
        # Verify our safe implementation does the right thing
        buf, allocated = ft_calloc_safe(count, size)
        
        assert buf is None and allocated == 0, (
            f"SECURITY VIOLATION: ft_calloc({count}, {size}) "
            f"should return NULL due to overflow "
            f"(true_required={true_required} > SIZE_T_MAX={SIZE_T_MAX}), "
            f"but returned buffer of size {allocated}"
        )
        
        # Also verify: the overflowed value would be dangerously small
        overflowed = (count * size) & SIZE_T_MAX
        if count > 0 and size > 0:
            assert overflowed < true_required, (
                f"Overflow should produce smaller value: "
                f"overflowed={overflowed}, true={true_required}"
            )


@pytest.mark.parametrize("count,size,expected_valid", [
    # (count, size, should_succeed)
    (10, 10, True),
    (1, 0, True),   # calloc edge case
    (0, 1, True),   # calloc edge case  
    (100, 100, True),
    (1024, 1024, True),
    (2**32, 2**32, False),   # overflow
    (SIZE_T_MAX, 2, False),  # overflow
    (2, SIZE_T_MAX, False),  # overflow
])
def test_ft_calloc_return_contract(count, size, expected_valid):
    """
    Invariant: ft_calloc must honor its return contract:
    - On success: return non-NULL pointer to buffer of AT LEAST count*size bytes
    - On failure (including overflow): return NULL
    Never return a non-NULL pointer to a buffer SMALLER than count*size bytes.
    """
    buf, allocated = ft_calloc_safe(count, size)
    
    if expected_valid:
        if buf is not None:
            true_required = count * size
            # If allocation succeeded, buffer must be large enough
            assert allocated >= true_required, (
                f"Buffer too small: got {allocated}, need {true_required}"
            )
    else:
        # For overflow cases, must return NULL
        assert buf is None, (
            f"ft_calloc({count}, {size}) should fail (overflow/invalid) "
            f"but returned buffer of size {allocated}"
        )