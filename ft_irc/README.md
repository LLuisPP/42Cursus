*This project has been created as part of the 42 curriculum by flperez-, lgracia- and lprieto-.*

# ft_irc — Internet Relay Chat Server

## Description

**ft_irc** is a C++98 project whose objective is to build a simplified but functional **IRC (Internet Relay Chat) server**, similar in behavior to real IRC servers used on the Internet.

The server listens on a TCP port and accepts connections from multiple IRC clients at the same time. Each connected client must authenticate using a password, choose a nickname and a username.

Once connected, clients can:
- Join or leave channels
- Send messages to all users in a channel
- Send private messages to other users
- Receive messages in real time from the server

Channels are managed by **operators**, who have additional permissions such as:
- Removing users from a channel
- Inviting users to private channels
- Setting or changing the channel topic
- Restricting access using modes (invite-only, password-protected channels, user limits, etc.)

From a technical perspective, the server is designed to handle many connected users at the same time without freezing or slowing down. Instead of waiting for one client to finish before attending another, the server constantly checks which connections are ready to send or receive data and processes them efficiently.

Because data sent over a network can arrive in small or incomplete pieces, the server must be able to accumulate and reconstruct messages correctly before interpreting them. This ensures that commands are processed reliably even under poor network conditions.

All of this is implemented while matching the behavior expected by standard IRC clients and respecting the limitations imposed by the C++98 standard.

---

## Instructions

### Compilation

Compile the project using the provided `Makefile`:

<div align="center">
<table>
  <tr>
    <td>Available rules:</td>
    <td>The project is compiled using:</td>
  </tr>
  <tr>
    <td>
      - <code>make</code> <br>
      - <code>make clean</code> <br>
      - <code>make fclean</code> <br>
      - <code>make sanitize</code> <br>
      - <code>make re</code> <br>
    </td>
    <td>
      - <code>c++</code> <br>
      - Flags: <code>-Wall -Wextra -Werror</code> <br>
      - Standard: <code>-std=c++98</code> <br>
    </td>
  </tr>
</table>
</div>
---

### Execution

Run the IRC server as follows:

```bash
./ircserv <port> <password>
```

Where:
- `<port>` is the TCP port on which the server will listen for incoming connections.
- `<password>` is required by clients to authenticate with the server.

Example:
```bash
./ircserv 6667 test
```

---

### Usage

You must use a **real IRC client** as a reference client (for example: `HexChat`, or similar).

Using the reference client, users must be able to:
- Authenticate with the server
- Set a nickname and username
- Join and leave channels
- Send and receive private messages
- Exchange messages in channels

Channel operators can additionally:
- Kick users (`KICK`)
- Invite users (`INVITE`)
- Change or view the channel topic (`TOPIC`)
- Manage channel modes (`MODE`):
  - `i` — invite-only channel
  - `t` — restrict topic changes to operators
  - `k` — channel password
  - `o` — operator privileges
  - `l` — user limit

Once connected, clients can:
- Join or leave channels <br>
  ```bash
  /JOIN #channel
  ```
  ```bash
  /PART #channel
  ```
- Send messages to all users in a channel <br>
  ```bash
  /PRIVMGS #channel :message
  ```
- Send private messages to other users <br>
  ```bash
  /PRIVMGS <nickname> :message
  ```
- Receive messages in real time from the server

Channels are managed by **operators**, who have additional permissions such as:
- Removing users from a channel <br>
  ```bash
  /KICK #channel <nickname>
  ```
- Inviting users to private channels <br>
  ```bash
  /INVITE <nickname> #channel
  ```
- Setting or changing the channel topic <br>
  ```bash
  /TOPIC #channel :new topic
  ```
- Restricting access using modes (invite-only, password-protected channels, user limits, etc.) <br>
  ```bash
  /MODE #channel [modes]
  ```

---

## Resources

### Technical references

- RFC 1459 — Internet Relay Chat Protocol - <a href="https://www.rfc-editor.org/rfc/rfc1459">Link</a>  
- Beej’s Guide to Network Programming - <a href="https://beej.us/guide/bgnet/">Link</a>  
- <code>man</code> pages:
  - <code>socket</code> - <a href="https://man7.org/linux/man-pages/man2/socket.2.html">Link</a>
  - <code>bind</code> - <a href="https://man7.org/linux/man-pages/man2/bind.2.html">Link</a>
  - <code>listen</code> - <a href="https://man7.org/linux/man-pages/man2/listen.2.html">Link</a>
  - <code>accept</code> - <a href="https://man7.org/linux/man-pages/man2/accept.2.html">Link</a>
  - <code>poll</code> - <a href="https://man7.org/linux/man-pages/man2/poll.2.html">Link</a>
  - <code>fcntl</code> - <a href="https://man7.org/linux/man-pages/man2/fcntl.2.html">Link</a>
  - <code>send</code> - <a href="https://man7.org/linux/man-pages/man2/send.2.html">Link</a>
  - <code>recv</code> - <a href="https://man7.org/linux/man-pages/man2/recv.2.html">Link</a>


---

### Use of Artificial Intelligence

AI tools were used **only as a support resource**, in accordance with the subject rules.

Specifically, AI was used to:
- Clarify theoretical concepts related to sockets, non-blocking I/O, and multiplexing
- Help understand the IRC protocol structure and command flow
- Assist in debugging by explaining error messages or unexpected behaviors

AI was **not used to generate complete functions or core logic** that was copied blindly.  
All generated suggestions were carefully reviewed, understood, adapted, and validated manually.  
Full responsibility for the final implementation and design choices was taken by the author.

Peer discussions and manual testing were used to validate correctness and understanding.

## Evaluation tests

This section lists **practical, copy-paste friendly commands** that can be used during evaluation to quickly demonstrate compliance with the mandatory requirements of the ft_irc subject.

All tests are intended to be run on **Ubuntu/Linux**, as used during evaluation.

---

### No forking (fork is prohibited)

The server must run as a **single process** with **no child processes**.

```bash
pstree -p $(pidof ircserv)
```


### Single `poll()` usage

Only one `poll()` (or equivalent) must be used to handle all I/O operations.

```bash
grep -R "poll(" .
```

Runtime observation (optional):

```bash
strace -e poll ./ircserv 6667 test
```


### Non-blocking file descriptors

All sockets and file descriptors must be set to non-blocking mode.

Runtime verification:

```bash
strace -e fcntl ./ircserv 6667 password
```

---

### No read/write without `poll()`

All `recv()` / `send()` operations must occur only after `poll()` signals readiness.

```bash
strace -e poll,recv,send ./ircserv 6667 test
```

---

### Multiple clients simultaneously

The server must handle multiple clients concurrently without blocking.

Terminal n:
```bash
./ircserv 6667 test
```
and so on in 'n' terminals as you want

---

### Partial message handling

The server must correctly reconstruct commands received in multiple packets.

```bash
nc -C 127.0.0.1 6667
```

Input sequence:
```text
PASS <password>
NICK batman
```
