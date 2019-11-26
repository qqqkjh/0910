#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
/* 시그널을 이용하여 자식 프로세스들을 제어한다. */
int main( )
{
   int pid1, pid2;

   pid1 = fork( );
   if (pid1 == 0) {
      while (1) {
         sleep(1);
         printf("프로세스 [1] 실행\n");
      }
   }

   pid2 = fork( );
if (pid2 == 0) {
      while (1) {
         sleep(1);
         printf("프로세스 [2] 실행\n");
      }
   }
   sleep(2);
   kill(pid1, SIGSTOP);
   sleep(2);
   kill(pid1, SIGCONT);
   sleep(2);
   kill(pid2, SIGSTOP);
   sleep(2);
   kill(pid2, SIGCONT);
   sleep(2);
   kill(pid1, SIGKILL);
   kill(pid2, SIGKILL);
}
