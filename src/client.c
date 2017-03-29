#include "cliserv.h"

int main(int argc,char *argv[])
{
    struct sockaddr_in serv,cli;
    char request[REQUEST], reply[REPLY];
    int sockfd, n,clilen;
    if(argc != 2)
        err_quit("usage:udpcli <IP address of server>");
    if((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) <0)
        err_sys("socket error");

    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr(argv[1]);
    serv.sin_port = htons(UDP_SERV_PORT);
	char msg[5] = "hello";
    //printf("%d     %s\n",serv.sin_port,serv.sin_addr.s_addr);
    //if(sendto(sockfd, msg, 5,0, (SA) &serv,sizeof(serv)) != REQUEST)
    if(sendto(sockfd, msg, 5,0, (SA) &serv,sizeof(serv)) != 5)
        err_sys("sendto error");


    clilen = sizeof(cli);
    if((n = recvfrom(sockfd,reply,REPLY ,0 ,&cli,&clilen))<0)
        err_sys("recvfrom error");
	printf("%s\n",reply);
    exit(0);
}
