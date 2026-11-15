# Variation 2 – Find the Sum of N Numbers (Array Sum)

---

## Part A: TCP Implementation (Experiment 5 Style)

### Aim
The client reads n integers from the user and sends them to the server using TCP. The server computes the sum of the numbers and sends the sum back to the client.

### Algorithm for Server (TCP)
1. Start the program and create a TCP socket using `socket(AF_INET, SOCK_STREAM, 0)`.
2. Initialize the server address structure (`AF_INET`, `INADDR_ANY`, port `8080`), bind using `bind()`, and listen using `listen()`.
3. Accept a client connection using `accept()`.
4. Receive the count of numbers `n` and the integer array `arr` from the client using `read()`.
5. Initialize `sum = 0`. Traverse the array from `i = 0` to `n - 1` and compute `sum += arr[i]`.
6. Send the calculated `sum` back to the client using `write()`.
7. Close the sockets and stop.

### Algorithm for Client (TCP)
1. Start the program, create a TCP socket, and connect to the server (`127.0.0.1`, port `8080`) using `connect()`.
2. Read the count `n` and the `n` numbers into array `arr` from the user.
3. Send `n` and `arr` to the server using `write()`.
4. Receive `sum` from the server using `read()` and display it.
5. Close the socket and stop.

---

## Part B: UDP Implementation (Experiment 6 Style)

### Aim
The client reads n numbers and sends them to the server using UDP. The server calculates their sum and sends the result back to the client.

### Algorithm for Server (UDP)
1. Start the program and create a UDP socket using `socket(AF_INET, SOCK_DGRAM, 0)`.
2. Initialize the server address (`AF_INET`, `INADDR_ANY`, port `8080`) and bind using `bind()`.
3. Receive the count `n` and the array `arr` from the client using `recvfrom()`.
4. Initialize `sum = 0`. Loop from `i = 0` to `n - 1` and add `arr[i]` to `sum`.
5. Send `sum` back to the client using `sendto()`.
6. Close the socket and stop.

### Algorithm for Client (UDP)
1. Start the program, create a UDP socket, and initialize the server address (`AF_INET`, port `8080`, `INADDR_ANY`).
2. Read the count `n` and `n` integers into array `arr` from the user.
3. Send `n` and `arr` to the server using `sendto()`.
4. Receive `sum` from the server using `recvfrom()` and display it.
5. Close the socket and stop.
