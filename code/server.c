/*
    TCP-Server
*/
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include <unistd.h>
#include<string.h>
#include <arpa/inet.h>

void main()
{
 int sockfd,connfd,sin_size,l,n,len;
 char operator;
 int op1,op2,result;
 //socket creation
 if((sockfd=socket(AF_INET,SOCK_STREAM,0))>0)
  printf("socket created sucessfully\n");  
 struct sockaddr_in servaddr;           
 struct sockaddr_in clientaddr;
//assigning IP,Port
 servaddr.sin_family=AF_INET;//Server Domain
 servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");//Server IP Adress
 servaddr.sin_port=6006;//Port on which the data to be sent 
//Binding newly created socket to the given IP
 if((bind(sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr)))==0)
 printf("bind sucessful\n");   
 //listen for connections on a socket
 if((listen(sockfd,5))==0) 
  printf("listen sucessful\n");
 
 sin_size = sizeof(struct sockaddr_in);
 //Server Accepts the data packet from the client
 if((connfd=accept(sockfd,(struct sockaddr *)&clientaddr,&sin_size))>0);
 printf("accept sucessful\n");
 //Server recives the data from the Client 
 read(connfd, &operator,sizeof(operator));
 read(connfd,&op1,sizeof(op1));
 read(connfd,&op2,sizeof(op2));
 //code for calculator functioning 
 switch(operator)
 {
  case '+':
   result=op1 + op2;
   printf("Result is: %d + %d = %d\n",op1, op2, result);
   break;
  case '-':
   result=op1 - op2;
          printf("Result is: %d - %d = %d\n",op1, op2, result);
          break;
  case '*':
   result=op1 * op2;
          printf("Result is: %d * %d = %d\n",op1, op2, result);
          break;
  case '/':
   result=op1 / op2;
          printf("Result is: %d / %d = %d\n",op1, op2, result);
          break;
  default:
          printf("ERROR: Unsupported Operation");
     }
//Server is sendind the result to the Client
 write(connfd,&result,sizeof(result)); 
 //Clocse Socket
 close(sockfd);

}
