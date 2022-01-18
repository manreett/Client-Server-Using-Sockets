/*
    TCP-Client
*/
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include <unistd.h>
#include<string.h>
#include<strings.h>
#include <arpa/inet.h>
void main()
{
 int sockfd,sin_size,con,n,len;
 char operator;
 int op1,op2,result;
 if((sockfd=socket(AF_INET,SOCK_STREAM,0))>0)//Here TCP Socket is Created  
 printf("socket created sucessfully\n");
  struct sockaddr_in servaddr;
  //assigning IP,Port
 servaddr.sin_family=AF_INET;
 servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
 servaddr.sin_port=6006;
 sin_size = sizeof(struct sockaddr_in);
 //Connecting client socket to server socket 
 if((con=connect(sockfd,(struct sockaddr *) &servaddr, sin_size))==0); //initiate a connection on a socket
  printf("connect sucessful\n");
 
  printf("Enter any one operation:\n + \n -\n /  \n* \n");
 
 scanf("%c", &operator);
 printf("\n");
 printf("Enter operands:\n");
 scanf("%d %d",&op1, &op2);
 //sending the iput values to the server
 write(sockfd,&operator,sizeof(operator));
 write(sockfd,&op1,sizeof(op1));
 write(sockfd,&op2,sizeof(op2));
 //Reeving  and displaying the message received from the Server
 read(sockfd,&result,sizeof(result));
 printf("Operation result from server=%d\n",result);
 //Close the socket
 close(sockfd);
}
