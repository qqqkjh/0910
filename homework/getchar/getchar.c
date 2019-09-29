#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#define MAX_LENGTH 64

int main(int argc, char const *argv[])
{
    char buf[MAX_LENGTH];
 

    char view;
    int fd;
    
    
    fd = open(argv[1],O_RDONLY|O_CREAT,0644);
    scanf("%s",buf);
    write(fd,buf,sizeof(buf));
    fd = open(argv[1],O_RDONLY);

    while ((read(fd,&buf,sizeof(buf)))>0) {

    
    view = buf[0];
   
    printf("%c\n", view);
    
    for(int i=0; i<strlen(buf); i++){
        buf[i]=buf[i+1];
    }
    write(fd,buf,MAX_LENGTH);
    
    }


        close(fd);
          exit(0);








}

