#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include"student.h"
#define START_ID 1401001


int main(int argc, char *argv[]){
  
    int fd,id;
    struct student rec;
    struct flock lock;


    if(argc < 2){
        fprintf(stderr, "사용법 : %s 파일\n", argv[0]);
        exit(1);

    }

     if(fd = open(argv[1],O_RDWR)==-1){
        perror(argv[1]);
        exit(2);

    }


    printf("\n 검색할 학생의 학번입력 : ");
    while (scanf("%d", &id)==1){

       lock.l_type = F_WRLCK;
       lock.l_whence = SEEK_SET;
       lock.l_start = (id-START_ID) *sizeof(rec);
       lock.l_len =sizeof(rec);
       if(fcntl(fd,F_SETLKW, &lock)==-1){
           perror(argv[1]);
           exit(3);
       }

       lseek(fd, (long)(id-START_ID)*sizeof(rec),SEEK_SET);
       if((read(fd, &rec, sizeof(rec))>0) && (rec.id !=0)){
        printf("이름:%s\t 학번:%d\t 점수:%d\n", rec.name,rec.id,rec.score);
        }else
       {   printf("레코드 %d 읎다\n ",id);}

       printf("새로운 학번 이름 점수 : ");
       scanf("%d %s %d",&rec.id,(char*)rec.name,&rec.score);
       lseek(fd,(long)-sizeof(rec), SEEK_CUR);
       write(fd, &rec, sizeof(rec));

       lock.l_type = F_UNLCK;
       fcntl(fd, F_SETLK,&lock);
       printf("\n 수정할 학생의 학번 입력 :");
       
       
    }

    close(fd);
    exit(0);
}