#include <stdio.h>
#include <stdbool.h>
int n=100;
char items[100];
int head=0;
int tail=0;

bool enqueue(char c){
    if(tail==n){
	if(head==0)
	    return false;
	for(int i=head;i<tail;i++){
            items[i-head]=items[i];
	}
	tail-=head;
	head=0;
        items[tail++]=c;
        return true;
    }
    items[tail++]=c;
    return true;
}

char dequeue(){
    if(head==tail)
	return 0;
    return items[head++];
}

int main(){
    for(int i=1;i<n;i++){
        enqueue(i);
    }

    for(int i=0;i<100;i++){
        printf("%c \n",dequeue());
    }

    printf("华丽的分割线------------------------------------------\n");

    for(int i=90;i<n;i++){
        enqueue(i);
    }
    for(int i=0;i<10;i++){
        printf("%c \n",dequeue());
    }
    return 1;
}
