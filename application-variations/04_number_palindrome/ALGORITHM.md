# Variation 4 – Check Whether a Number is a Palindrome

---

## Part A: TCP Implementation (Experiment 5 Style)

### Aim
The client inputs an integer and sends it to the server using TCP. The server determines whether the number reads the same forwards and backwards and sends the result back to the client.

### Algorithm for Server (TCP)
1. Start the program and create a TCP socket using `socket(AF_INET, SOCK_STREAM, 0)`.
2. Initialize the server address (`AF_INET`, `INADDR_ANY`, port `8080`), bind using `bind()`, and listen using `listen()`.
3. Accept a client connection using `accept()`.
4. Receive the integer `num` from the client using `read()`.
5. Set `original = num` and initialize `rev = 0`.
6. Repeat while `num > 0`: compute `rem = num % 10`, `rev = rev * 10 + rem`, and `num = num / 10`.
7. If `original == rev`, set `result = "Palindrome Number"`; else set `result = "Not a Palindrome Number"`.
8. Send `result` to the client using `write()`, close sockets, and stop.

### Algorithm for Client (TCP)
1. Start the program, create a TCP socket, and connect to the server (`127.0.0.1`, port `8080`) using `connect()`.
2. Read an integer `num` from the user and send it to the server using `write()`.
3. Receive the result string from the server using `read()` and display it.
4. Close the socket and stop.

---

## Part B: UDP Implementation (Experiment 6 Style)

### Aim
The client inputs a number and sends it to the server using UDP. The server checks whether it is a palindrome and sends the result back to the client.

### Algorithm for Server (UDP)
1. Start the program and create a UDP socket using `socket(AF_INET, SOCK_DGRAM, 0)`.
2. Initialize the server address (`AF_INET`, `INADDR_ANY`, port `8080`) and bind using `bind()`.
3. Receive the integer `num` from the client using `recvfrom()`.
4. Store `original = num` and initialize `rev = 0`.
5. While `num > 0`: compute `rem = num % 10`, `rev = rev * 10 + rem`, and `num = num / 10`.
6. If `original == rev`, set `result = "Palindrome Number"`; else set `result = "Not a Palindrome Number"`.
7. Send `result` back to the client using `sendto()`, close the socket, and stop.

### Algorithm for Client (UDP)
1. Start the program, create a UDP socket, and set the server address (`AF_INET`, port `8080`, `INADDR_ANY`).
2. Read an integer `num` from the user and send it to the server using `sendto()`.
3. Receive the result from the server using `recvfrom()` and display it.
4. Close the socket and stop.
