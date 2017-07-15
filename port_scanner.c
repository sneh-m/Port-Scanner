/* 
	Author:: SNEH KUMAR MISHRA
	
	Simple program to print all the active ports of the host machine
*/
#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include <unistd.h>
#include<errno.h>

#define MAXPORT 65535

int main()
{	
	for(int i=1; i<=MAXPORT; i++)
	{
		int sockfd = socket(AF_INET,SOCK_STREAM,0);
		struct sockaddr_in myaddr;
		myaddr.sin_family = AF_INET;
		myaddr.sin_addr.s_addr = htonl(0);
		myaddr.sin_port = htons(i);
		int x = bind(sockfd,(struct sockaddr *) &myaddr,sizeof(myaddr));
		
		
		//printf("%d\n",x);
		if(( x < 0)&&(errno = EADDRINUSE))
		{
			printf("%d :: PORT IN USE\n",i);
		}
		else
		{
			printf("%d :: ACTIVE PORT\n",i);
		}
		close(sockfd);
	}
	return 0;
}
