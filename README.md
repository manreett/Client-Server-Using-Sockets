# Sockets-Client_Server_TCP
In the TCP Server Client program , the following are the main steps that take place in :

# In the TCP Server  the following steps are performed:

1.	A TCP socket is created using create().
2.	Then this socket is bind to the server address using bind(). Bind()               operation is usually assigning a name to a socket 
3.	Then we use a listen() call , which put the socket in a passive mode. In this mode, server sockets wait for the client to approach the server to make a connection.
4.	Then we use accept(), that accepts the connection , connection between the client and server is made and they are ready to transfer data 
5.	Then it goes back to the third step to see listen if any other connection call is made 

# In the TCP Client  the following steps are performed:
1.	Here also , a TCP socket is created using create()
2.	Then this newly created client socket is connected to the server socket 
