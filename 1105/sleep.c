#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/time.h>
int main(int argc, char *argv[]){
	struct timeval start,end;
	double gap;
	
	printf("hello\n");
	gettimeofday(&start,NULL);
	sleep(atoi(argv[1]));
	gettimeofday(&end,NULL);
	printf("bye\n");
	gap=end.tv_sec + end.tv_usec /1000000.0 - start.tv_sec - start.tv_usec /1000000.0;
	printf("%f\n",gap);
	return 0;
}

