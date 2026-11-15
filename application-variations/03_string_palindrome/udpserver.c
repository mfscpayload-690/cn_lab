/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 3: Check Whether a String is a Palindrome
 * Component: UDP Server (udpserver.c)
 * 
 * Compilation:
 *   gcc udpserver.c -o udpserver
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
      char buffer[MAX], result[50];
      struct sockaddr_in server_addr, client_addr;
      socklen_t len = sizeof(client_addr);

       sockfd = socket(AF_INET, SOCK_DGRAM, 0);
       server_addr.sin_family = AF_INET;
       server_addr.sin_addr.s_addr = INADDR_ANY;
       server_addr.sin_port = htons(PORT);

       bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
       printf("UDP Server Running...\n");

       recvfrom(sockfd, buffer, MAX, 0, (struct sockaddr *)&client_addr, &len);
       printf("Received: %s\n", buffer);

       int slen = strlen(buffer);
       int flag = 1;
       for(int i = 0; i < slen / 2; i++)
       {
           if(buffer[i] != buffer[slen - 1 - i])
           {
               flag = 0;
               break;
           }
       }

       if(flag)
           strcpy(result, "Palindrome String");
       else
           strcpy(result, "Not a Palindrome String");

      sendto(sockfd, result, strlen(result) + 1, 0, (struct sockaddr *)&client_addr, len);
      printf("Result sent.\n");

       close(sockfd);
       return 0;
  }
