#include "cliserv.h"

int main(int argc,char *argv[])
{
	struct sockaddr_in serv;
	char request[REQUEST],reply[REPLY];
	int sockfd, n;
	if((sockfd = socket(PF_INET,SOCK_STREAM, 0))< 0 )
		err_sys("socket error");
	memset(&serv, 0, sizeof(serv));
	serv.sin_family = AF_INET;
	serv.sin_addr.s_addr = inet_addr(argv[1]);
	serv.sin_port = htons(TCP_SERV_PORT);

	if (connect(sockfd, (SA) &serv, sizeof(serv)) < 0)
		err_sys("connect error");
	//if (write(sockfd,request,REQUEST) != REQUEST)
	if (write(sockfd,"hello",sizeof("hello")) != sizeof("hello"))
		err_sys("write error");
	if (shutdown(sockfd, 1) < 0){
		err_sys("shutdown error");
	}
	if ((n = read_stream(sockfd, reply , REPLY)) < 0)
		err_sys("read error");

	exit(0);

}
