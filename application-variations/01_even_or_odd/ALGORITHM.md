# Variation 1 – Check Whether a Number is Even or Odd

---

## Part A: TCP Implementation (Experiment 5 Style)

### Aim
The client inputs an integer and sends it to the server using TCP. The server checks whether the number is Even or Odd and sends the result string back to the client, which displays it.

### Algorithm for Server (TCP)
1. Start the program.
2. Create a TCP socket using `socket(AF_INET, SOCK_STREAM, 0)`.
3. Initialize the server address structure: set family to `AF_INET`, IP address to `INADDR_ANY`, and port to `8080`.
4. Bind the socket to the specified address using `bind()`.
5. Put the socket into listening mode using `listen()` and display "Waiting for client connection...".
6. Accept a client connection using `accept()`.
7. Receive the integer `num` from the client using `read()`.
8. Check divisibility by 2: if `num % 2 == 0`, set `result = "Even Number"`; otherwise set `result = "Odd Number"`.
9. Send the result string to the client using `write()`.
10. Close the client socket and server socket, then stop.

### Algorithm for Client (TCP)
1. Start the program and create a TCP socket using `socket(AF_INET, SOCK_STREAM, 0)`.
2. Initialize the server address structure with `AF_INET`, port `8080`, and IP `127.0.0.1`.
3. Connect to the server using `connect()`.
4. Read an integer `num` from the user and send it to the server using `write()`.
5. Receive the result string from the server using `read()` and display it.
6. Close the socket connection and stop.

---

## Part B: UDP Implementation (Experiment 6 Style)

### Aim
The client inputs an integer and sends it to the server using UDP. The server checks whether the number is Even or Odd and sends the result back to the client.

### Algorithm for Server (UDP)
1. Start the program and create a UDP socket using `socket(AF_INET, SOCK_DGRAM, 0)`.
2. Initialize the server address structure (`AF_INET`, `INADDR_ANY`, port `8080`) and bind using `bind()`.
3. Display "UDP Server Running..." and wait for a number from the client using `recvfrom()`.
4. If `num % 2 == 0`, set `result = "Even Number"`; else set `result = "Odd Number"`.
5. Send the result string back to the client using `sendto()`.
6. Close the socket and stop.

### Algorithm for Client (UDP)
1. Start the program and create a UDP socket using `socket(AF_INET, SOCK_DGRAM, 0)`.
2. Initialize the server address structure (`AF_INET`, port `8080`, `INADDR_ANY`).
3. Read an integer `num` from the user and send it to the server using `sendto()`.
4. Receive the result string from the server using `recvfrom()` and display it.
5. Close the socket and stop.
