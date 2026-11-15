/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 9: Matrix Total Sum & Diagonal Sum
 * Component: TCP Server (server.c)
 * 
 * Compilation:
 *   gcc server.c -o server
 * 
 * Compatibility: Ubuntu 16.04 / 18.04 / 20.04 / 22.04+ (POSIX C99/C11)
 */

#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <arpa/inet.h>
  #define PORT 8080
  #define MAX 20

  int main()
  {
      int server_fd, new_socket;
      struct sockaddr_in address;
      int addrlen = sizeof(address);
      int n, matrix[MAX][MAX];
      int total_sum = 0, diag_sum = 0;
      char result[100];

       server_fd = socket(AF_INET, SOCK_STREAM, 0);
       address.sin_family = AF_INET;
       address.sin_addr.s_addr = INADDR_ANY;
       address.sin_port = htons(PORT);

       bind(server_fd, (struct sockaddr *)&address, sizeof(address));
       listen(server_fd, 3);
       printf("Waiting for client connection...\n");

      new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
      read(new_socket, &n, sizeof(int));
      read(new_socket, matrix, sizeof(matrix));

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
       write(new_socket, result, sizeof(result));
       printf("Result Sent to Client: %s\n", result);

       close(new_socket);
       close(server_fd);
       return 0;
  }
