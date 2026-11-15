/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 8: Count Vowels, Consonants, and Digits
 * Component: UDP Server (udpserver.c)
 * 
 * Compilation:
 *   gcc udpserver.c -o udpserver
 * 
 * Compatibility: Ubuntu 16.04 / 18.04 / 20.04 / 22.04+ (POSIX C99/C11)
 */

#include <stdio.h>
  #include <string.h>
  #include <ctype.h>
  #include <unistd.h>
  #include <arpa/inet.h>
  #define PORT 8080
  #define MAX 1024

  int main()
  {
      int sockfd;
      char buffer[MAX], result[MAX];
      int vowels = 0, consonants = 0, digits = 0;
      struct sockaddr_in server_addr, client_addr;
      socklen_t len = sizeof(client_addr);

       sockfd = socket(AF_INET, SOCK_DGRAM, 0);
       server_addr.sin_family = AF_INET;
       server_addr.sin_addr.s_addr = INADDR_ANY;
       server_addr.sin_port = htons(PORT);

       bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
       printf("UDP Server Running...\n");

       recvfrom(sockfd, buffer, MAX, 0, (struct sockaddr *)&client_addr, &len);
       printf("Received: %s\n", buffer);

       for(int i = 0; buffer[i] != '\0'; i++)
       {
           char ch = tolower(buffer[i]);
           if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
               vowels++;
           else if(ch >= 'a' && ch <= 'z')
               consonants++;
           else if(ch >= '0' && ch <= '9')
               digits++;
       }

      sprintf(result, "Vowels: %d, Consonants: %d, Digits: %d", vowels, consonants, digits);
      sendto(sockfd, result, strlen(result) + 1, 0, (struct sockaddr *)&client_addr, len);
      printf("Counts sent.\n");

       close(sockfd);
       return 0;
  }
