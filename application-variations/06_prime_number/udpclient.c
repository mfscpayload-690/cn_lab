/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 6: Check Whether a Number is Prime
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

  int main()
  {
      int sockfd, num;
      char result[50];
      struct sockaddr_in server_addr;
      socklen_t len = sizeof(server_addr);

       sockfd = socket(AF_INET, SOCK_DGRAM, 0);
       server_addr.sin_family = AF_INET;
       server_addr.sin_port = htons(PORT);
       server_addr.sin_addr.s_addr = INADDR_ANY;

       printf("Enter a number: ");
       scanf("%d", &num);

      sendto(sockfd, &num, sizeof(int), 0, (struct sockaddr *)&server_addr, len);
      recvfrom(sockfd, result, sizeof(result), 0, (struct sockaddr *)&server_addr, &len);
      printf("Result from Server: %s\n", result);

       close(sockfd);
       return 0;
  }
