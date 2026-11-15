# Variation 9 – Matrix Total Sum & Diagonal Sum

---

## Part A: TCP Implementation (Experiment 5 Style)

### Aim
The client inputs the matrix order N, generates an N × N square matrix with random numbers in the range [1, 50], and sends it to the server via TCP. The server calculates both the sum of all matrix elements and the sum of the principal diagonal elements and sends the result back to the client.

### Algorithm for Server (TCP)
1. Start the program and create a TCP socket using `socket(AF_INET, SOCK_STREAM, 0)`.
2. Initialize the server address (`AF_INET`, `INADDR_ANY`, port `8080`), bind using `bind()`, and listen using `listen()`.
3. Accept a client connection using `accept()`.
4. Receive the matrix order `n` and the matrix from the client using `read()`.
5. Initialize `total_sum = 0` and `diag_sum = 0`.
6. Traverse the matrix using nested loops (`i = 0` to `n - 1`, `j = 0` to `n - 1`):
   - Add `matrix[i][j]` to `total_sum`.
   - If `i == j`, add `matrix[i][j]` to `diag_sum`.
7. Format both sums into the result string using `sprintf()` and send it to the client using `write()`.
8. Close the sockets and stop.

### Algorithm for Client (TCP)
1. Start the program, create a TCP socket, and connect to the server (`127.0.0.1`, port `8080`) using `connect()`.
2. Read the matrix order `n` from the user and generate an n × n matrix using `rand() % 50 + 1`.
3. Send `n` and `matrix` to the server using `write()`.
4. Receive the result string from the server using `read()` and display it.
5. Close the socket and stop.

---

## Part B: UDP Implementation (Experiment 6 Style)

### Aim
The client generates an N × N matrix and sends it to the server using UDP. The server calculates the total sum and diagonal sum of the matrix and sends the result back to the client.

### Algorithm for Server (UDP)
1. Start the program and create a UDP socket using `socket(AF_INET, SOCK_DGRAM, 0)`.
2. Initialize the server address (`AF_INET`, `INADDR_ANY`, port `8080`) and bind using `bind()`.
3. Receive the matrix order `n` and matrix from the client using `recvfrom()`.
4. Initialize `total_sum = 0` and `diag_sum = 0`.
5. Traverse the matrix using nested loops (`i = 0` to `n - 1`, `j = 0` to `n - 1`): add `matrix[i][j]` to `total_sum`, and if `i == j`, add `matrix[i][j]` to `diag_sum`.
6. Format both sums into result using `sprintf()` and send it to the client using `sendto()`.
7. Close the socket and stop.

### Algorithm for Client (UDP)
1. Start the program, create a UDP socket, and set the server address (`AF_INET`, port `8080`, `INADDR_ANY`).
2. Read the matrix order `n` from the user and generate an n × n matrix.
3. Send `n` and `matrix` to the server using `sendto()`.
4. Receive result from the server using `recvfrom()` and display it.
5. Close the socket and stop.
