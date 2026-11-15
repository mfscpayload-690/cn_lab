/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 2: Find Sum of N Numbers (Array Sum)
 * Component: UDP Client (udpclient.c)
 * 
 * Compilation:
 *   gcc udpclient.c -o udpclient
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
      int sockfd, n, arr[MAX], sum;
      struct sockaddr_in server_addr;
      socklen_t len = sizeof(server_addr);

       sockfd = socket(AF_INET, SOCK_DGRAM, 0);
       server_addr.sin_family = AF_INET;
       server_addr.sin_port = htons(PORT);
       server_addr.sin_addr.s_addr = INADDR_ANY;

       printf("Enter count of numbers: ");
       scanf("%d", &n);
       printf("Enter %d numbers:\n", n);
       for(int i = 0; i < n; i++)
       {
           scanf("%d", &arr[i]);
       }

       sendto(sockfd, &n, sizeof(int), 0, (struct sockaddr *)&server_addr, len);
       sendto(sockfd, arr, sizeof(arr), 0, (struct sockaddr *)&server_addr, len);
       recvfrom(sockfd, &sum, sizeof(int), 0, (struct sockaddr *)&server_addr, &len);

       printf("Sum from Server: %d\n", sum);

       close(sockfd);
       return 0;
  }
