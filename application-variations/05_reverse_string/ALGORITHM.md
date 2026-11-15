# Variation 5 – Reverse a String

---

## Part A: TCP Implementation (Experiment 5 Style)

### Aim
The client inputs a string and sends it to the server using TCP. The server reverses the string character by character and sends the reversed string back to the client.

### Algorithm for Server (TCP)
1. Start the program and create a TCP socket using `socket(AF_INET, SOCK_STREAM, 0)`.
2. Initialize the server address (`AF_INET`, `INADDR_ANY`, port `8080`), bind using `bind()`, and listen using `listen()`.
3. Accept a client connection using `accept()`.
4. Receive the string `str` from the client using `read()`.
5. Find string length `len = strlen(str)`.
6. Loop from `i = 0` to `len - 1` and copy `rev[i] = str[len - 1 - i]`. Set `rev[len] = '\0'`.
7. Send the reversed string `rev` to the client using `write()`, close sockets, and stop.

### Algorithm for Client (TCP)
1. Start the program, create a TCP socket, and connect to the server (`127.0.0.1`, port `8080`) using `connect()`.
2. Read a string `str` from the user and send it to the server using `write()`.
3. Receive the reversed string `rev` from the server using `read()` and display it.
4. Close the socket and stop.

---

## Part B: UDP Implementation (Experiment 6 Style)

### Aim
The client inputs a string and sends it to the server using UDP. The server reverses the string and sends the reversed string back to the client.

### Algorithm for Server (UDP)
1. Start the program and create a UDP socket using `socket(AF_INET, SOCK_DGRAM, 0)`.
2. Initialize the server address (`AF_INET`, `INADDR_ANY`, port `8080`) and bind using `bind()`.
3. Receive the string `buffer` from the client using `recvfrom()`.
4. Find length `slen = strlen(buffer)`.
5. Loop from `i = 0` to `slen - 1` and copy `rev[i] = buffer[slen - 1 - i]`. Set `rev[slen] = '\0'`.
6. Send `rev` back to the client using `sendto()`, close the socket, and stop.

### Algorithm for Client (UDP)
1. Start the program, create a UDP socket, and set the server address (`AF_INET`, port `8080`, `INADDR_ANY`).
2. Read a string `message` from the user and send it to the server using `sendto()`.
3. Receive the reversed string `buffer` from the server using `recvfrom()` and display it.
4. Close the socket and stop.
