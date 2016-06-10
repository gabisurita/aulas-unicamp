#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

int main(int argc, char* argv[]){
  
  
  /* Checa se a entrada é válida. */ 
  if(argc != 2){
    printf("Incorrect Use. Usage: request <URL> <port>");
    return 1;
  }

  int port = 80;
  char Addr[] = "www.dca.fee.unicamp.br\0";

  /* Cria um socket */
  int sock = socket(AF_INET, SOCK_STREAM, 0); 

  /* Checa se o socket é válido. */
  if(sock < 0){
    printf("Error creating socket.");
    return 2;
  }
  
  struct sockaddr_in Server;
  
  Server.sin_family = AF_INET;
  Server.sin_port = htons(port);
  Server.sin_addr = Addr;
  
  if

  return 0;
}
