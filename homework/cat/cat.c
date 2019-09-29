#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include "catboard.h"
int main(int argc, char *argv[]){
int fd;
struct catboard board;

if(argc < 2){
        fprintf(stderr,"사용법 :%s file\n", argv[0]);
        exit(0);

    }

//파일이 존재할떄와 존재하지 않을때
if((fd = open(argv[1],O_RDONLY))==-1){
    fd = open(argv[1],O_RDONLY|O_CREAT,0644);
     scanf("%s",board.str);
     write(fd, &board, sizeof(board) );
     printf("%s\n",board.str);
         close(fd);
         exit(1);
   
}
else{
read(fd, &board, sizeof(board));
printf("%s\n",board.str);


    close(fd);
    exit(2);



}
close(fd);
exit(3);
}