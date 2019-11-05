#include <stdio.h>
#include <stdlib.h>
static void my_exit1(void),my_exit2(void);
static void exit_handler1(void) {
	    printf("첫 번째 exit 처리기\n");
	     }

static void exit_handler2(void) {
	    printf("두 번째 exit 처리기\n");
	     }


int main(void) {
if(atexit(exit_handler1) != 0) perror("exit_handler1 등록할 수 없음");
if(atexit(exit_handler2) != 0) perror("exit_handler2 등록할 수 없음");
   printf("main 끝 \n");
 exit(0);
 }

