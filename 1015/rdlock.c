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

    if(fd = open(argv[1],O_RDONLY)==-1){
        perror(argv[1]);
        exit(2);

    }

    printf("\n 검색할 학생의 학번입력 : ");
    while (scanf("%d", &id)==1)
    {
       lock.l_type = F_RDLCK;
       lock.l_whence = SEEK_SET;
       lock.l_start = (id-START_ID) *sizeof(rec);
       lock.l_len =sizeof(rec);
       if(fcntl(fd,F_SETLKW, &lock)==-1){
           perror(argv[1]);
           exit(3);
       }
       
       lseek(fd, (id-START_ID) * sizeof(rec),SEEK_SET);
       if((read(fd, &rec, sizeof(rec))>0) && (rec.id !=0))
        printf("이름 %s\t 학번 %d\t 점수 %d\n", rec.name, (int)rec.id, (int)rec.score);
       else
       {
           printf("레코드 %d 없음\n",id);
       }
        
        lock.l_type = F_UNLCK;
        fcntl(fd,F_SETLK, &lock);
        printf("\n검색할학생의 학번입력:");
    }
    
    close(fd);
    exit(0);


}