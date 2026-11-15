/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 5: Reverse a String
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
  #define MAX 100

  int main()
  {
      int server_fd, new_socket;
      struct sockaddr_in address;
      int addrlen = sizeof(address);
      char str[MAX], rev[MAX];

       server_fd = socket(AF_INET, SOCK_STREAM, 0);
       address.sin_family = AF_INET;
       address.sin_addr.s_addr = INADDR_ANY;
       address.sin_port = htons(PORT);

       bind(server_fd, (struct sockaddr *)&address, sizeof(address));
       listen(server_fd, 3);
       printf("Waiting for client connection...\n");

      new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
      read(new_socket, str, sizeof(str));

       int len = strlen(str);
       for(int i = 0; i < len; i++)
       {
           rev[i] = str[len - 1 - i];
       }
       rev[len] = '\0';

       write(new_socket, rev, sizeof(rev));
       printf("Reversed String Sent to Client: %s\n", rev);

       close(new_socket);
       close(server_fd);
       return 0;
  }
