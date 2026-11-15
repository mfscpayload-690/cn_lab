/*
 * PCCSL507 Networks Lab - Application Variations
 * Variation 2: Find Sum of N Numbers (Array Sum)
 * Component: TCP Client (client.c)
 * 
 * Compilation:
 *   gcc client.c -o client
 * 
 * Compatibility: Ubuntu 16.04 / 18.04 / 20.04 / 22.04+ (POSIX C99/C11)
 */

#include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <arpa/inet.h>
  #define PORT 8080
  #define MAX 50

  int main()
  {
      int sock = 0;
      struct sockaddr_in serv_addr;
      int n, arr[MAX], sum;

       sock = socket(AF_INET, SOCK_STREAM, 0);
       serv_addr.sin_family = AF_INET;
       serv_addr.sin_port = htons(PORT);
       inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

       connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

       printf("Enter count of numbers: ");
       scanf("%d", &n);
       printf("Enter %d numbers:\n", n);
       for(int i = 0; i < n; i++)
       {
           scanf("%d", &arr[i]);
       }

       write(sock, &n, sizeof(int));
       write(sock, arr, sizeof(arr));
       read(sock, &sum, sizeof(int));
       printf("Sum Received from Server: %d\n", sum);

       close(sock);
       return 0;
  }
