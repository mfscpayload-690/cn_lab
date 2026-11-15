/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 1: Check Whether a Number is Even or Odd
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

  int main()
  {
      int sockfd, num;
      char result[50];
      struct sockaddr_in server_addr, client_addr;
      socklen_t len = sizeof(client_addr);

       sockfd = socket(AF_INET, SOCK_DGRAM, 0);
       server_addr.sin_family = AF_INET;
       server_addr.sin_addr.s_addr = INADDR_ANY;
       server_addr.sin_port = htons(PORT);

       bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
       printf("UDP Server Running...\n");

       recvfrom(sockfd, &num, sizeof(int), 0, (struct sockaddr *)&client_addr, &len);
       printf("Received number: %d\n", num);

       if(num % 2 == 0)
           strcpy(result, "Even Number");
       else
           strcpy(result, "Odd Number");

      sendto(sockfd, result, sizeof(result), 0, (struct sockaddr *)&client_addr, len);
      printf("Result sent.\n");

       close(sockfd);
       return 0;
  }
