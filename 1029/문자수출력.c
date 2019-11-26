#include<stdio.h>
int main(int argc ,char* argv[]){

    char c;
    int n;
    

    printf("반복할수 입력: " );
    scanf("%d",&n);
    getchar(); //버퍼 문제떄문에 있어야됨 이걸로 버퍼를 비움 버퍼를안비우면 원래있는 쓰래기값을 바로 넣어버림(이경우 이전 숫자를 받을떄 같이 받은 공백이 쓰래기값)
    printf("반복할 문자 입력: " );
    scanf("%c",&c);



    printf("당신은 %c 와 %d 를 입력했습니다\n",c,n);
    for(int i =0; i<n; i++){
        
        
        
        
        printf("%c",c);
    }
    
    }
