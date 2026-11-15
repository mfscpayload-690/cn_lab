# Variation 3 – Check Whether a String is a Palindrome

---

## Part A: TCP Implementation (Experiment 5 Style)

### Aim
The client inputs a string and sends it to the server using TCP. The server checks whether the string is a palindrome or not and sends the result back to the client.

### Algorithm for Server (TCP)
1. Start the program and create a TCP socket using `socket(AF_INET, SOCK_STREAM, 0)`.
2. Initialize the server address (`AF_INET`, `INADDR_ANY`, port `8080`), bind using `bind()`, and listen using `listen()`.
3. Accept a client connection using `accept()`.
4. Receive the string `str` from the client using `read()`.
5. Find string length `len = strlen(str)` and initialize `flag = 1`.
6. Loop from `i = 0` to `len / 2 - 1`: if `str[i] != str[len - 1 - i]`, set `flag = 0` and break.
7. If `flag == 1`, set `result = "Palindrome String"`; else set `result = "Not a Palindrome String"`.
8. Send `result` to the client using `write()`, close sockets, and stop.

### Algorithm for Client (TCP)
1. Start the program, create a TCP socket, and connect to the server (`127.0.0.1`, port `8080`) using `connect()`.
2. Read a string `str` from the user and send it to the server using `write()`.
3. Receive the result string from the server using `read()` and display it.
4. Close the socket and stop.

---

## Part B: UDP Implementation (Experiment 6 Style)

### Aim
The client inputs a string and sends it to the server using UDP. The server checks whether the string is a palindrome and sends the result back to the client.

### Algorithm for Server (UDP)
1. Start the program and create a UDP socket using `socket(AF_INET, SOCK_DGRAM, 0)`.
2. Initialize the server address (`AF_INET`, `INADDR_ANY`, port `8080`) and bind using `bind()`.
3. Receive the string `buffer` from the client using `recvfrom()`.
4. Find length `slen = strlen(buffer)` and initialize `flag = 1`.
5. Loop from `i = 0` to `slen / 2 - 1`: if `buffer[i] != buffer[slen - 1 - i]`, set `flag = 0` and break.
6. If `flag == 1`, set `result = "Palindrome String"`; else set `result = "Not a Palindrome String"`.
7. Send `result` back to the client using `sendto()`, close the socket, and stop.

### Algorithm for Client (UDP)
1. Start the program, create a UDP socket, and set the server address (`AF_INET`, port `8080`, `INADDR_ANY`).
2. Read a string `message` from the user and send it to the server using `sendto()`.
3. Receive the response into `buffer` using `recvfrom()` and display it.
4. Close the socket and stop.
