import subprocess

tests = [
    # Básicos
    ("0", [
        "char: Non displayable",
        "int: 0",
        "float: 0.0f",
        "double: 0.0"
    ]),
    ("42", [
        "char: '*'",
        "int: 42",
        "float: 42.0f",
        "double: 42.0"
    ]),
    ("-42", [
        "char: impossible",
        "int: -42",
        "float: -42.0f",
        "double: -42.0"
    ]),
    ("127", [
        "char: Non displayable",
        "int: 127",
        "float: 127.0f",
        "double: 127.0"
    ]),
    ("128", [
        "char: impossible",
        "int: 128",
        "float: 128.0f",
        "double: 128.0"
    ]),
    ("255", [
        "char: impossible",
        "int: 255",
        "float: 255.0f",
        "double: 255.0"
    ]),
    ("-1", [
        "char: impossible",
        "int: -1",
        "float: -1.0f",
        "double: -1.0"
    ]),
    ("2147483647", [
        "char: impossible",
        "int: 2147483647",
        "float: 2147483647.0f",
        "double: 2147483647.0"
    ]),
    ("2147483648", [
        "char: impossible",
        "int: impossible",
        "float: 2147483648.0f",
        "double: 2147483648.0"
    ]),
    ("-2147483648", [
        "char: impossible",
        "int: -2147483648",
        "float: -2147483648.0f",
        "double: -2147483648.0"
    ]),
    ("-2147483649", [
        "char: impossible",
        "int: impossible",
        "float: -2147483649.0f",
        "double: -2147483649.0"
    ]),
    # Letras y símbolos
    ("a", [
        "char: 'a'",
        "int: 97",
        "float: 97.0f",
        "double: 97.0"
    ]),
    ("A", [
        "char: 'A'",
        "int: 65",
        "float: 65.0f",
        "double: 65.0"
    ]),
    ("z", [
        "char: 'z'",
        "int: 122",
        "float: 122.0f",
        "double: 122.0"
    ]),
    ("$", [
        "char: '$'",
        "int: 36",
        "float: 36.0f",
        "double: 36.0"
    ]),
    (" ", [
        "char: ' '",
        "int: 32",
        "float: 32.0f",
        "double: 32.0"
    ]),
    ("\n", [
        "char: Non displayable",
        "int: 10",
        "float: 10.0f",
        "double: 10.0"
    ]),
    ("'b'", [
        "char: 'b'",
        "int: 98",
        "float: 98.0f",
        "double: 98.0"
    ]),
    # Pseudo-literales y especiales
    ("nan", [
        "char: impossible",
        "int: impossible",
        "float: nanf",
        "double: nan"
    ]),
    ("nanf", [
        "char: impossible",
        "int: impossible",
        "float: nanf",
        "double: nan"
    ]),
    ("inf", [
        "char: impossible",
        "int: impossible",
        "float: inff",
        "double: inf"
    ]),
    ("inff", [
        "char: impossible",
        "int: impossible",
        "float: inff",
        "double: inf"
    ]),
    ("-inf", [
        "char: impossible",
        "int: impossible",
        "float: -inff",
        "double: -inf"
    ]),
    ("-inff", [
        "char: impossible",
        "int: impossible",
        "float: -inff",
        "double: -inf"
    ]),
    ("+inf", [
        "char: impossible",
        "int: impossible",
        "float: inff",
        "double: inf"
    ]),
    ("+inff", [
        "char: impossible",
        "int: impossible",
        "float: inff",
        "double: inf"
    ]),
    # Flotantes
    ("4.2", [
        "char: Non displayable",
        "int: 4",
        "float: 4.2f",
        "double: 4.2"
    ]),
    ("4.2f", [
        "char: Non displayable",
        "int: 4",
        "float: 4.2f",
        "double: 4.2"
    ]),
    ("0.0", [
        "char: Non displayable",
        "int: 0",
        "float: 0.0f",
        "double: 0.0"
    ]),
    ("-0.0", [
        "char: Non displayable",
        "int: 0",
        "float: -0.0f",
        "double: -0.0"
    ]),
    ("123456789.0", [
        "char: impossible",
        "int: 123456789",
        "float: 123456789.0f",
        "double: 123456789.0"
    ]),
    # Casos límite y errores
    ("", [
        "Invalid literal!"
    ]),
    ("hello", [
        "Invalid literal!"
    ]),
    ("!", [
        "char: '!'",
        "int: 33",
        "float: 33.0f",
        "double: 33.0"
    ]),
    ("'!'", [
        "char: '!'",
        "int: 33",
        "float: 33.0f",
        "double: 33.0"
    ]),
]

import struct

def c_float_str(val):
    # Simula el redondeo de float de C++ (IEEE 754, 32 bits)
    try:
        f = float(val)
        packed = struct.pack('f', f)
        unpacked = struct.unpack('f', packed)[0]
        # Formato como en el output: 1 decimal y 'f'
        return f"float: {unpacked:.1f}f"
    except Exception:
        return None

def run_test(arg, expected):
    result = subprocess.run(["./convert", arg], capture_output=True, text=True)
    output = result.stdout.strip().splitlines()
    # Para cada línea esperada, permite variantes (por ejemplo, float redondeado)
    expected_groups = []
    for exp in expected:
        group = [exp]
        if exp.startswith("float: "):
            val = exp[7:-1]
            try:
                float(val)
                alt = c_float_str(val)
                if alt != exp and alt is not None:
                    group.append(alt)
            except Exception:
                pass
        expected_groups.append(group)
    # Para cada grupo, al menos una variante debe estar en la salida
    ok = True
    for group in expected_groups:
        if not any(any(variant in line for line in output) for variant in group):
            ok = False
            break
    print(f"Test '{arg}': {'OK' if ok else 'FAIL'}")
    if not ok:
        print("Expected (any of each group):")
        for group in expected_groups:
            print("  - " + " | ".join(group))
        print("Got:")
        print("\n".join(output))
        print()
    return ok

ok_count = 0
fail_count = 0

for arg, expected in tests:
    result = run_test(arg, expected)
    if result:
        ok_count += 1
    else:
        fail_count += 1

GREEN = "\033[92m"
RED = "\033[91m"
RESET = "\033[0m"
print(f"{GREEN}Tests OK: {ok_count}{RESET}")
print(f"{RED}Tests FAIL: {fail_count}{RESET}")