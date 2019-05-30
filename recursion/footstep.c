#include <stdio.h>

int count=0;

int step(int n){
    if(n==1)
	return 1;
    if(n==2)
        return 2;	
    return step(n-1)+step(n-2);
}
int main(){
    printf("请输入一个整数：");
    scanf("%d",&count);
    printf("n=%d,有%d种走法\n",count,step(count));
}
