/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 8: Count Vowels, Consonants, and Digits
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
  #define MAX 1024

  int main()
  {
      int sock = 0;
      struct sockaddr_in serv_addr;
      char str[MAX], result[MAX];

       sock = socket(AF_INET, SOCK_STREAM, 0);
       serv_addr.sin_family = AF_INET;
       serv_addr.sin_port = htons(PORT);
       inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

       connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

       printf("Enter a sentence: ");
       fgets(str, MAX, stdin);

       write(sock, str, sizeof(str));
       read(sock, result, sizeof(result));
       printf("Result from Server:\n%s\n", result);

       close(sock);
       return 0;
  }
