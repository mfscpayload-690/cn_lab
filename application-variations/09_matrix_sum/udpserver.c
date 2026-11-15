/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 9: Matrix Total Sum & Diagonal Sum
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
  #define MAX 20

  int main()
  {
      int sockfd, n, matrix[MAX][MAX];
      int total_sum = 0, diag_sum = 0;
      char result[100];
      struct sockaddr_in server_addr, client_addr;
      socklen_t len = sizeof(client_addr);

       sockfd = socket(AF_INET, SOCK_DGRAM, 0);
       server_addr.sin_family = AF_INET;
       server_addr.sin_addr.s_addr = INADDR_ANY;
       server_addr.sin_port = htons(PORT);

       bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
       printf("UDP Server Running...\n");

      recvfrom(sockfd, &n, sizeof(int), 0, (struct sockaddr *)&client_addr, &len);
      recvfrom(sockfd, matrix, sizeof(matrix), 0, (struct sockaddr *)&client_addr, &len);

       for(int i = 0; i < n; i++)
       {
           for(int j = 0; j < n; j++)
           {
               total_sum += matrix[i][j];
               if(i == j)
                   diag_sum += matrix[i][j];
           }
       }

      sprintf(result, "Total Sum = %d, Diagonal Sum = %d", total_sum, diag_sum);
      sendto(sockfd, result, sizeof(result), 0, (struct sockaddr *)&client_addr, len);
      printf("Result sent: %s\n", result);

       close(sockfd);
       return 0;
  }
