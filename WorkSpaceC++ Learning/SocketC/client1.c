/*
 * client1.c
 *
 *  Created on: 18-Feb-2018
 *      Author: udham
 */
#if 0
	Conclusion:
	-We can  communicate b/w two thread using  socket
=====================================================================
	-All most Any TCP/UDP communication,use to happen through ,socket
	-Socket used bu
	-UML Digram of C++ Interface for TCP IP
	-Server socket and client socket both dervide from socket class
	-server socket can be inherited to ,webserver,Ecocaht,multiserver

	https://www.geeksforgeeks.org/socket-programming-cc/
	http://pubs.opengroup.org/onlinepubs/7908799/xns/arpainet.h.html
#endif
#include <stdio.h>
#include <string.h>
#include<sys/socket.h>
#include<unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include<pthread.h>


//Grace full exit for thread?

int ServerTrue=0;
void  * pthread1(void * data)
{
	//crete socket
   int valread;
   struct sockaddr_in  address;
   int  new_socket=0;
   int server_fd;
   char str[100];
   int addrlen = sizeof(address);
   char buffer[1024] = { 0 };
   char* hello = "Hello from server";

   if ((server_fd = socket(AF_INET,
	                          SOCK_STREAM, 0)) == 0) {
	        perror("socket failed");
	       // exit(EXIT_FAILURE);
    }

	//bind socket
   	  address.sin_family = AF_INET;
      address.sin_addr.s_addr = INADDR_ANY;
      address.sin_port = htons(8090);

      address.sin_family = AF_INET;
      address.sin_addr.s_addr = INADDR_ANY;
      address.sin_port = htons(8090);

      // the port 8090
       if (bind(server_fd, (struct sockaddr*)&address,
                                sizeof(address)) < 0)
       {
           perror("bind failed");
             // exit(EXIT_FAILURE);
       }

	   //listen socket: put server port passive mode
       if (listen(server_fd, 3) < 0)
       {
               perror("listen");
               //exit(EXIT_FAILURE);
      }
      ServerTrue=1;
       ///create  new  socket give response  to  its client
      if ((new_socket = accept(server_fd,
	                  (struct sockaddr*)&address,
	                  (socklen_t*)&addrlen)) < 0)
      {
	        perror("accept");
	       // exit(EXIT_FAILURE);
      }
      while(1)
      {
       //read data
    	   valread = read(new_socket, str, sizeof(str));
    	   int i, j, temp;
    	   int l = strlen(str);
    	   printf("\nString sent by client:%s\n", str);
    	   //Apply logic
    	   // loop to reverse the string
    	   for (i = 0, j = l - 1; i < j; i++, j--)
	       {
	            temp = str[i];
	            str[i] = str[j];
	           str[j] = temp;
	       }
    	   //send data
    	   send(new_socket, str, sizeof(str), 0);
    	   printf("Server Thread: Send revrse string back to  its client:  \n");
    	   sleep(5);
       }
}

void * pthread2(void * data)
{
	printf("Server is ready cretea client thread:\n");
	while(ServerTrue !=1);

	struct sockaddr_in server_adress;
		//(struct sockaddr*)&serv_addr,
		int clientsockfd = 0, valread;
		int return_value=0;
		int readlenth;
		char str[100];
		//1.0 Creating socket file descriptor
		clientsockfd = socket(AF_INET,SOCK_STREAM,0);
		if(clientsockfd <0)
		{
			printf("Socket opening error \n");
		}
		//2.o set server address
		memset(&server_adress,'0',sizeof(server_adress));

		server_adress.sin_family = AF_INET;
		server_adress.sin_port = htons(8090);

		inet_pton(AF_INET,"127.0.0.1", &server_adress.sin_addr);

		//3.connect the socket
		return_value=connect(clientsockfd,(struct sockaddr*)&server_adress,sizeof(server_adress));
		if(return_value < 0)
		{
			printf("Socket Error");
		}

		while(1)
		{
			//4.Send the data
			send(clientsockfd,"udhamSinghYadav",sizeof("udhamSinghYadav"),0);

			//read data
			readlenth=read(clientsockfd,str,16);

			printf("Client Print Receievde string from Server==%s\n", str);
		 	sleep(2);
		}
}

int main()
{
	 pthread_attr_t thAttr;
	 int policy = 0;
	    int max_prio_for_policy = 0;

	    pthread_attr_init(&thAttr);
	    pthread_attr_getschedpolicy(&thAttr, &policy);
	    max_prio_for_policy = sched_get_priority_max(policy);

//-----------------------------------------------------------

	pthread_t pthreadid1;
	pthread_t pthreadid2;
	pthread_create(&pthreadid1,NULL,pthread1,NULL);
	pthread_setschedprio(pthreadid1, 5);
//------------------------------------------------------------
	//while(ServerTrue)
	pthread_create(&pthreadid2,NULL,pthread2,NULL);

	pthread_setschedprio(pthreadid1, 1);
	pthread_join(pthreadid1,NULL);
	pthread_join(pthreadid2,NULL);
	printf("Main thread\n");
//-----------------------------------------------------------
	pthread_attr_destroy(&thAttr);
	return 0;
}





