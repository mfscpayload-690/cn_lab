# PCCSL507 Networks Lab — Application Variations (Exp 5 & Exp 6)

This repository contains the complete extracted, formatted, verified, and bug-free C source codes for all **9 Common Exam Variations** from the Networks Lab Exam Guide.

Each variation is implemented separately for:
- **Experiment 5 Style (TCP)**: `server.c` and `client.c`
- **Experiment 6 Style (UDP)**: `udpserver.c` and `udpclient.c`

Total: **36 C programs** across 9 application variations.

---

## Compatibility Guarantee (Ubuntu 16.04, 18.04, 20.04+)

All programs are written in standard POSIX C (C99 / C11 / gnu11) and have been tested and verified across:
- **Ubuntu 16.04 LTS (Xenial Xerus)** — GCC 5.4, glibc 2.23
- **Ubuntu 18.04 LTS (Bionic Beaver)** — GCC 7.4, glibc 2.27
- **Ubuntu 20.04 LTS (Focal Fossa)** — GCC 9.3, glibc 2.31
- **Ubuntu 22.04 LTS / 24.04 LTS & modern Linux**

Key portability features:
- Standard socket headers: `<stdio.h>`, `<stdlib.h>`, `<string.h>`, `<unistd.h>`, `<arpa/inet.h>`, `<ctype.h>`, `<time.h>`
- Clean 0-warning compilation with `gcc -Wall -Wextra -std=c99`
- No non-standard or external dependencies.

---

## Directory Structure

```text
application-variations/
├── Makefile                                # Builds all 36 programs or cleans them
├── README.md                               # Comprehensive lab reference & guide
├── test_all.py                             # Automated test suite for all 18 pairs
├── 01_even_or_odd/                         # Variation 1: Even or Odd Number
│   ├── server.c    (TCP Server)
│   ├── client.c    (TCP Client)
│   ├── udpserver.c (UDP Server)
│   └── udpclient.c (UDP Client)
├── 02_sum_of_n_numbers/                    # Variation 2: Sum of N Numbers (Array Sum)
│   ├── server.c    (TCP Server)
│   ├── client.c    (TCP Client)
│   ├── udpserver.c (UDP Server)
│   └── udpclient.c (UDP Client)
├── 03_string_palindrome/                   # Variation 3: String Palindrome Check
│   ├── server.c    (TCP Server)
│   ├── client.c    (TCP Client)
│   ├── udpserver.c (UDP Server)
│   └── udpclient.c (UDP Client)
├── 04_number_palindrome/                   # Variation 4: Number Palindrome Check
│   ├── server.c    (TCP Server)
│   ├── client.c    (TCP Client)
│   ├── udpserver.c (UDP Server)
│   └── udpclient.c (UDP Client)
├── 05_reverse_string/                      # Variation 5: Reverse a String
│   ├── server.c    (TCP Server)
│   ├── client.c    (TCP Client)
│   ├── udpserver.c (UDP Server)
│   └── udpclient.c (UDP Client)
├── 06_prime_number/                        # Variation 6: Prime Number Check
│   ├── server.c    (TCP Server)
│   ├── client.c    (TCP Client)
│   ├── udpserver.c (UDP Server)
│   └── udpclient.c (UDP Client)
├── 07_factorial/                           # Variation 7: Factorial of a Number
│   ├── server.c    (TCP Server)
│   ├── client.c    (TCP Client)
│   ├── udpserver.c (UDP Server)
│   └── udpclient.c (UDP Client)
├── 08_vowels_consonants_digits/            # Variation 8: Count Vowels, Consonants, Digits
│   ├── server.c    (TCP Server)
│   ├── client.c    (TCP Client)
│   ├── udpserver.c (UDP Server)
│   └── udpclient.c (UDP Client)
└── 09_matrix_sum/                          # Variation 9: Matrix Total Sum & Diagonal Sum
    ├── server.c    (TCP Server)
    ├── client.c    (TCP Client)
    ├── udpserver.c (UDP Server)
    └── udpclient.c (UDP Client)
```

---

## Quick Architecture Reference: TCP (Exp 5) vs UDP (Exp 6)

| Feature | Experiment 5 (TCP) | Experiment 6 (UDP) |
| :--- | :--- | :--- |
| **Socket Type** | `SOCK_STREAM` | `SOCK_DGRAM` |
| **Server Setup** | `socket()` → `bind()` → `listen()` → `accept()` | `socket()` → `bind()` (no listen, no accept) |
| **Client Setup** | `socket()` → `connect()` | `socket()` (no connect) |
| **Data Transfer** | `read()` / `write()` | `recvfrom()` / `sendto()` |
| **Connection State** | Connection-oriented, reliable stream | Connectionless, independent datagrams |

---

## Variations Summary Table

| Var | Application Question | Key Data Exchange (Client ➔ Server ➔ Client) | TCP Files | UDP Files |
| :---: | :--- | :--- | :--- | :--- |
| **1** | Even or Odd | `int num` ➔ `char result[50]` | `server.c`, `client.c` | `udpserver.c`, `udpclient.c` |
| **2** | Sum of N Numbers | `int n, int arr[50]` ➔ `int sum` | `server.c`, `client.c` | `udpserver.c`, `udpclient.c` |
| **3** | String Palindrome | `char str[100]` ➔ `char result[50]` | `server.c`, `client.c` | `udpserver.c`, `udpclient.c` |
| **4** | Number Palindrome | `int num` ➔ `char result[50]` | `server.c`, `client.c` | `udpserver.c`, `udpclient.c` |
| **5** | Reverse a String | `char str[100]` ➔ `char rev[100]` | `server.c`, `client.c` | `udpserver.c`, `udpclient.c` |
| **6** | Prime Number Check | `int num` ➔ `char result[50]` | `server.c`, `client.c` | `udpserver.c`, `udpclient.c` |
| **7** | Factorial of a Number | `int num` ➔ `int fact` | `server.c`, `client.c` | `udpserver.c`, `udpclient.c` |
| **8** | Vowels, Consonants, Digits | `char str[1024]` ➔ `char result[1024]` | `server.c`, `client.c` | `udpserver.c`, `udpclient.c` |
| **9** | Matrix Sum & Diagonal Sum | `int n, int mat[20][20]` ➔ `char result[100]` | `server.c`, `client.c` | `udpserver.c`, `udpclient.c` |

---

## How to Compile and Run

### Option 1: Using the Automated Makefile (Batch Build)

```bash
cd application-variations
make all      # Compiles all 36 programs across all 9 directories
make clean    # Removes all compiled binaries
make test     # Runs the automated verification suite
```

### Option 2: Manual Terminal Execution (Exam Style)

Open **Terminal 1** for the server, and **Terminal 2** for the client.

#### Example 1: TCP Even / Odd (Variation 1)
**Terminal 1 (Server):**
```bash
cd application-variations/01_even_or_odd
gcc server.c -o server
./server
```
*Output: `Waiting for client connection...`*

**Terminal 2 (Client):**
```bash
cd application-variations/01_even_or_odd
gcc client.c -o client
./client
```
*Prompt:* `Enter a number: 14`  
*Client Output:* `Result Received from Server: Even Number`  
*Server Output:* `Result Sent to Client: Even Number`

---

#### Example 2: UDP Even / Odd (Variation 1)
**Terminal 1 (Server):**
```bash
cd application-variations/01_even_or_odd
gcc udpserver.c -o udpserver
./udpserver
```
*Output: `UDP Server Running...`*

**Terminal 2 (Client):**
```bash
cd application-variations/01_even_or_odd
gcc udpclient.c -o udpclient
./udpclient
```
*Prompt:* `Enter a number: 7`  
*Client Output:* `Result from Server: Odd Number`  
*Server Output:* `Received number: 7` \ `Result sent.`

---

## Exam Tips & Troubleshooting

1. **`Address already in use` error**:
   - If a TCP server terminates, the Linux kernel holds port 8080 in `TIME_WAIT` for ~60 seconds.
   - **Solution A**: Wait 30-60 seconds before restarting the server.
   - **Solution B**: In `server.c` and `client.c`, change `#define PORT 8080` to another port, e.g., `8081` or `8082`.
   - **Solution C**: Add `SO_REUSEADDR` before `bind()`:
     ```c
     int opt = 1;
     setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
     ```

2. **Always start the Server before the Client**:
   - For TCP, if the server is not listening, the client will terminate with `Connection refused`.
   - For UDP, sending is connectionless, but the client will block waiting for a reply if the server isn't running.

