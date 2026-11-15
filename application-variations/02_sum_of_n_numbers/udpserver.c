/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 2: Find Sum of N Numbers (Array Sum)
 * Component: UDP Server (udpserver.c)
 * 
 * Compilation:
 *   gcc udpserver.c -o udpserver
 * 
 * Compatibility: Ubuntu 16.04 / 18.04 / 20.04 / 22.04+ (POSIX C99/C11)
 */

#include <stdio.h>
  #include <unistd.h>
  #include <arpa/inet.h>
  #define PORT 8080
  #define MAX 50

  int main()
  {
      int sockfd, n, arr[MAX], sum = 0;
      struct sockaddr_in server_addr, client_addr;
      socklen_t len = sizeof(client_addr);

       sockfd = socket(AF_INET, SOCK_DGRAM, 0);
       server_addr.sin_family = AF_INET;
       server_addr.sin_addr.s_addr = INADDR_ANY;
       server_addr.sin_port = htons(PORT);

       bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
       printf("UDP Server Running...\n");

       recvfrom(sockfd, &n, sizeof(int), 0, (struct sockaddr *)&client_addr, &len);
       recvfrom(sockfd, arr, sizeof(arr), 0, (struct sockaddr *)&client_addr, &len);

       for(int i = 0; i < n; i++)
       {
           sum += arr[i];
       }

       sendto(sockfd, &sum, sizeof(int), 0, (struct sockaddr *)&client_addr, len);
       printf("Sum (%d) sent.\n", sum);

       close(sockfd);
       return 0;
  }
