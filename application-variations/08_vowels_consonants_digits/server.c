/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 8: Count Vowels, Consonants, and Digits
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
  #include <ctype.h>
  #include <unistd.h>
  #include <arpa/inet.h>
  #define PORT 8080
  #define MAX 1024

  int main()
  {
      int server_fd, new_socket;
      struct sockaddr_in address;
      int addrlen = sizeof(address);
      char str[MAX], result[MAX];
      int vowels = 0, consonants = 0, digits = 0;

       server_fd = socket(AF_INET, SOCK_STREAM, 0);
       address.sin_family = AF_INET;
       address.sin_addr.s_addr = INADDR_ANY;
       address.sin_port = htons(PORT);

       bind(server_fd, (struct sockaddr *)&address, sizeof(address));
       listen(server_fd, 3);
       printf("Waiting for client connection...\n");

      new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
      read(new_socket, str, sizeof(str));

       for(int i = 0; str[i] != '\0'; i++)
       {
           char ch = tolower(str[i]);
           if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
               vowels++;
           else if(ch >= 'a' && ch <= 'z')
               consonants++;
           else if(ch >= '0' && ch <= '9')
               digits++;
       }

      sprintf(result, "Vowels: %d, Consonants: %d, Digits: %d", vowels, consonants, digits);
      write(new_socket, result, sizeof(result));
      printf("Counts Sent to Client: %s\n", result);

       close(new_socket);
       close(server_fd);
       return 0;
  }
