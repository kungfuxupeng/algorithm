#include <stdio.h>
struct ListNode {
   int val;
   struct ListNode *next;
};


struct ListNode* reverseList(struct ListNode* head){

    struct ListNode *nextNode;
    struct ListNode *preNode;
    struct ListNode *currentNode;
    preNode=NULL;
    currentNode=head;
    
    if(head!=NULL)
        do{
            nextNode=currentNode->next;
            currentNode->next=preNode;
            preNode=currentNode;
            currentNode=nextNode;
        }while(currentNode!=NULL);
    return preNode;
}
int main(){
    struct ListNode node1,node2,node3,node4,node5;
    node1.val=1;
    node1.next=&node2;
    node2.val=2;
    node2.next=&node3;
    node3.val=3;
    node3.next=&node4;
    node4.val=4;
    node4.next=&node5;
    node5.val=5;
    node5.next=NULL;
    struct ListNode *head=reverseList(&node1);
    struct ListNode *n=head;
    while(n!=NULL){
        printf("%d \n",n->val);
        n=n->next;
    }
    return 1;

}

