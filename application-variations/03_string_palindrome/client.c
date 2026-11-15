/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 3: Check Whether a String is a Palindrome
 * Component: TCP Client (client.c)
 * 
 * Compilation:
 *   gcc client.c -o client
 * 
 * Compatibility: Ubuntu 16.04 / 18.04 / 20.04 / 22.04+ (POSIX C99/C11)
 */

#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <arpa/inet.h>
  #define PORT 8080
  #define MAX 100

  int main()
  {
      int sock = 0;
      struct sockaddr_in serv_addr;
      char str[MAX], result[50];

       sock = socket(AF_INET, SOCK_STREAM, 0);
       serv_addr.sin_family = AF_INET;
       serv_addr.sin_port = htons(PORT);
       inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

       connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

       printf("Enter a string: ");
       scanf("%s", str);

       write(sock, str, sizeof(str));
       read(sock, result, sizeof(result));
       printf("Result Received from Server: %s\n", result);

       close(sock);
       return 0;
  }
