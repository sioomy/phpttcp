SRCDIR = ./src/
BINDIR = ./bin/
INCDIR = ./include/
OBJDIR = ./objs/

CC = gcc -I${INCDIR}
CFLAGS = -g -Wall 



#指定伪目标，可以忽略
.PHONY : all
all:${BINDIR}server ${BINDIR}client ${BINDIR}tcpclient

${BINDIR}server:${OBJDIR}server.o ${OBJDIR}errtool.o
	$(CC) -o ${BINDIR}server ${OBJDIR}server.o ${OBJDIR}errtool.o

${BINDIR}client:${OBJDIR}client.o ${OBJDIR}errtool.o
	$(CC) $(CFLAGS) -o ${BINDIR}client ${OBJDIR}client.o ${OBJDIR}errtool.o


#这里故意没依赖cliserv.h看看.h的依赖是不是必要
${BINDIR}tcpclient:${SRCDIR}tcpclient.c ${OBJDIR}errtool.o ${OBJDIR}read_stream.o
	$(CC) -o ${BINDIR}tcpclient ${SRCDIR}tcpclient.c ${OBJDIR}errtool.o ${OBJDIR}read_stream.o


${OBJDIR}server.o:${SRCDIR}server.c
	$(CC) $(CFLAGS) -o ${OBJDIR}server.o -Iinclude -c ${SRCDIR}server.c

${OBJDIR}errtool.o:${SRCDIR}errtool.c
	$(CC) $(CFLAGS) -o ${OBJDIR}errtool.o -c ${SRCDIR}errtool.c

${OBJDIR}read_stream.o:${SRCDIR}read_stream.c
	$(CC) $(CFLAGS) -o ${OBJDIR}read_stream.o -c ${SRCDIR}read_stream.c

${OBJDIR}client.o:${SRCDIR}client.c
	$(CC) $(CFLAGS) -o ${OBJDIR}client.o -c ${SRCDIR}client.c


clean:
	rm -rf ${BINDIR}* ${OBJDIR}*.o
