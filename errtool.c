#include "cliserv.h"

void err_quit(const char *str,...){
    printf("%s\n",str);
}
void err_sys(const char *str,...){
    printf("%s\n",str);
}
int read_stream(int fd,char *ptr,int maxbytes){
	int nleft, nread;
	nleft = maxbytes;
	while (nleft > 0){
		if((nread = read(fd,ptr,nleft)) < 0 )
		{
			return (nread);
		}else
			break;
		nleft -= nread;
		ptr += nread;
	}
	return (maxbytes - nleft);
}
