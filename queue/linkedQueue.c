#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct LinkedList
{
    int val;
    struct LinkedList *next;
};

struct LinkedList  *head=NULL,*tail=NULL;

bool enqueue(int val){
    struct LinkedList *p=(struct LinkedList *)malloc(sizeof(struct LinkedList));
    p->val=val;
    p->next=NULL;
    if(tail==NULL){
	tail=p;
	head=p;
    }else{
        tail->next=p;
	tail=tail->next;
    }
    return true;
}

int dequeue(){
    if(head==NULL){
        return 0;
    }
    int val=head->val;
    head=head->next;
    return val;
}

int main(){
    for(int i=0;i<10;i++){
        enqueue(i);
    }

    for(int i=0;i<15;i++){
	printf("%d \n",dequeue());
    }
    return 1;
}
