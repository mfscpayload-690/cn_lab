/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 5: Reverse a String
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
      char buffer[MAX], rev[MAX];
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
       for(int i = 0; i < slen; i++)
       {
           rev[i] = buffer[slen - 1 - i];
       }
       rev[slen] = '\0';

       sendto(sockfd, rev, strlen(rev) + 1, 0, (struct sockaddr *)&client_addr, len);
       printf("Reversed string sent.\n");

       close(sockfd);
       return 0;
  }
