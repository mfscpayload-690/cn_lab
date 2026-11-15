/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 9: Matrix Total Sum & Diagonal Sum
 * Component: UDP Client (udpclient.c)
 * 
 * Compilation:
 *   gcc udpclient.c -o udpclient
 * 
 * Compatibility: Ubuntu 16.04 / 18.04 / 20.04 / 22.04+ (POSIX C99/C11)
 */

#include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #include <unistd.h>
  #include <arpa/inet.h>
  #define PORT 8080
  #define MAX 20

  int main()
  {
      int sockfd, n, matrix[MAX][MAX];
      char result[100];
      struct sockaddr_in server_addr;
      socklen_t len = sizeof(server_addr);

       sockfd = socket(AF_INET, SOCK_DGRAM, 0);
       server_addr.sin_family = AF_INET;
       server_addr.sin_port = htons(PORT);
       server_addr.sin_addr.s_addr = INADDR_ANY;

       printf("Enter order of matrix: ");
       scanf("%d", &n);
       srand(time(0));
       printf("\nGenerated Matrix:\n");
       for(int i = 0; i < n; i++)
       {
           for(int j = 0; j < n; j++)
           {
               matrix[i][j] = rand() % 50 + 1;
               printf("%4d", matrix[i][j]);
           }
           printf("\n");
       }

      sendto(sockfd, &n, sizeof(int), 0, (struct sockaddr *)&server_addr, len);
      sendto(sockfd, matrix, sizeof(matrix), 0, (struct sockaddr *)&server_addr, len);
      recvfrom(sockfd, result, sizeof(result), 0, (struct sockaddr *)&server_addr, &len);

       printf("\nResult from Server: %s\n", result);

       close(sockfd);
       return 0;
  }
