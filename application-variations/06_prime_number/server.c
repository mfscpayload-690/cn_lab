/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 6: Check Whether a Number is Prime
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

  int main()
  {
      int server_fd, new_socket;
      struct sockaddr_in address;
      int addrlen = sizeof(address);
      int num, isPrime = 1;
      char result[50];

       server_fd = socket(AF_INET, SOCK_STREAM, 0);
       address.sin_family = AF_INET;
       address.sin_addr.s_addr = INADDR_ANY;
       address.sin_port = htons(PORT);

       bind(server_fd, (struct sockaddr *)&address, sizeof(address));
       listen(server_fd, 3);
       printf("Waiting for client connection...\n");

      new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
      read(new_socket, &num, sizeof(int));

       if(num <= 1)
           isPrime = 0;
       for(int i = 2; i <= num / 2; i++)
       {
           if(num % i == 0)
           {
               isPrime = 0;
               break;
           }
       }

       if(isPrime)
           strcpy(result, "Prime Number");
       else
           strcpy(result, "Not a Prime Number");

       write(new_socket, result, sizeof(result));
       printf("Result Sent to Client: %s\n", result);

       close(new_socket);
       close(server_fd);
       return 0;
  }
