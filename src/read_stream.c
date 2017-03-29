#include "cliserv.h"
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
