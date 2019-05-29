#include <stdio.h>
#include <stdbool.h>

char items[10];
int count=10;
int head=0;
int tail=0;

bool enqueue(char c){
    if((tail+1)%count==head)
	return false;
    items[tail]=c;
    tail=(tail+1)%count;
    return true;
}
char dequeue(){
    if(head==tail)
        return 0;
    return items[head++];
}

int main(){
    for(int i=80;i<120;i++){
        enqueue(i);
	if(i % 2 == 0)
	    printf("%c\n",dequeue());
    }
    return 1;
}
