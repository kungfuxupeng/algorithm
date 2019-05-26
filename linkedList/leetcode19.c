#include <stdio.h>
  struct ListNode {
      int val;
      struct ListNode *next;
  };


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head==NULL || n<=0)
        return head;
    struct ListNode* node=head;
    int i=0;
    while(node!=NULL){
        i++;
        node=node->next;
    }
    node=head;
    i=i-n;
    if(i==0){
        head=head->next;
        return head;
    }
    
    for(;i>1;i--){
        if(node==NULL)
            break;
        node=node->next;
    }
    if(node!=NULL && node->next!=NULL)
        node->next=node->next->next;
    return head;
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
    struct ListNode *head=removeNthFromEnd(&node1,2);
    struct ListNode *n=head;
    while(n!=NULL){
        printf("%d \n",n->val);
	n=n->next;
    }
    return 1;

}
