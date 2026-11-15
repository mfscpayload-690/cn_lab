/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 4: Check Whether a Number is a Palindrome
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

  int main()
  {
      int sockfd, num, original, rem, rev = 0;
      char result[50];
      struct sockaddr_in server_addr, client_addr;
      socklen_t len = sizeof(client_addr);

       sockfd = socket(AF_INET, SOCK_DGRAM, 0);
       server_addr.sin_family = AF_INET;
       server_addr.sin_addr.s_addr = INADDR_ANY;
       server_addr.sin_port = htons(PORT);

       bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
       printf("UDP Server Running...\n");

       recvfrom(sockfd, &num, sizeof(int), 0, (struct sockaddr *)&client_addr, &len);
       printf("Received number: %d\n", num);

       original = num;
       while(num > 0)
       {
           rem = num % 10;
           rev = rev * 10 + rem;
           num = num / 10;
       }

       if(original == rev)
           strcpy(result, "Palindrome Number");
       else
           strcpy(result, "Not a Palindrome Number");

      sendto(sockfd, result, sizeof(result), 0, (struct sockaddr *)&client_addr, len);
      printf("Result sent.\n");

       close(sockfd);
       return 0;
  }
