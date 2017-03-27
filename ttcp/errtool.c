#include "cliserv.h"

void err_quit(const char *str,...){
    printf("%s\n",str);
}
void err_sys(const char *str,...){
    printf("%s\n",str);
}
int read_stream(int fd,char *str,int xx){
    printf("%s\n",str);
}
