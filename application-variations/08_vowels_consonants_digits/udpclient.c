/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 8: Count Vowels, Consonants, and Digits
 * Component: UDP Client (udpclient.c)
 * 
 * Compilation:
 *   gcc udpclient.c -o udpclient
 * 
 * Compatibility: Ubuntu 16.04 / 18.04 / 20.04 / 22.04+ (POSIX C99/C11)
 */

#include <stdio.h>
  #include <string.h>
  #include <unistd.h>
  #include <arpa/inet.h>
  #define PORT 8080
  #define MAX 1024

  int main()
  {
      int sockfd;
      char message[MAX], buffer[MAX];
      struct sockaddr_in server_addr;
      socklen_t len = sizeof(server_addr);

       sockfd = socket(AF_INET, SOCK_DGRAM, 0);
       server_addr.sin_family = AF_INET;
       server_addr.sin_port = htons(PORT);
       server_addr.sin_addr.s_addr = INADDR_ANY;

       printf("Enter sentence:\n");
       fgets(message, MAX, stdin);

      sendto(sockfd, message, strlen(message) + 1, 0, (struct sockaddr *)&server_addr, len);
      recvfrom(sockfd, buffer, MAX, 0, (struct sockaddr *)&server_addr, &len);
      printf("\nResult from Server:\n%s\n", buffer);

       close(sockfd);
       return 0;
  }
