# Variation 8 – Count Vowels, Consonants, and Digits in a String

---

## Part A: TCP Implementation (Experiment 5 Style)

### Aim
The client inputs a sentence and sends it to the server using TCP. The server counts the number of vowels, consonants, and digits in the string and sends the formatted counts back to the client.

### Algorithm for Server (TCP)
1. Start the program and create a TCP socket using `socket(AF_INET, SOCK_STREAM, 0)`.
2. Initialize the server address (`AF_INET`, `INADDR_ANY`, port `8080`), bind using `bind()`, and listen using `listen()`.
3. Accept a client connection using `accept()`.
4. Receive the string `str` from the client using `read()`.
5. Initialize `vowels = 0`, `consonants = 0`, and `digits = 0`.
6. Traverse each character `ch = tolower(str[i])` until `'\0'`:
   - If `ch` is `'a'`, `'e'`, `'i'`, `'o'`, or `'u'`, increment `vowels`.
   - Else if `ch >= 'a' && ch <= 'z'`, increment `consonants`.
   - Else if `ch >= '0' && ch <= '9'`, increment `digits`.
7. Format the counts into `result` using `sprintf()` and send it to the client using `write()`.
8. Close the sockets and stop.

### Algorithm for Client (TCP)
1. Start the program, create a TCP socket, and connect to the server (`127.0.0.1`, port `8080`) using `connect()`.
2. Read a sentence `str` from the user using `fgets()` and send it to the server using `write()`.
3. Receive `result` from the server using `read()` and display it.
4. Close the socket and stop.

---

## Part B: UDP Implementation (Experiment 6 Style)

### Aim
The client inputs a sentence and sends it to the server using UDP. The server counts the vowels, consonants, and digits and sends the result back to the client.

### Algorithm for Server (UDP)
1. Start the program and create a UDP socket using `socket(AF_INET, SOCK_DGRAM, 0)`.
2. Initialize the server address (`AF_INET`, `INADDR_ANY`, port `8080`) and bind using `bind()`.
3. Receive the sentence `buffer` from the client using `recvfrom()`.
4. Initialize `vowels = 0`, `consonants = 0`, and `digits = 0`.
5. Traverse each character `ch = tolower(buffer[i])` and increment `vowels`, `consonants`, or `digits` accordingly.
6. Format the counts into `result` using `sprintf()` and send it to the client using `sendto()`.
7. Close the socket and stop.

### Algorithm for Client (UDP)
1. Start the program, create a UDP socket, and set the server address (`AF_INET`, port `8080`, `INADDR_ANY`).
2. Read a sentence `message` from the user using `fgets()` and send it to the server using `sendto()`.
3. Receive `buffer` from the server using `recvfrom()` and display it.
4. Close the socket and stop.
