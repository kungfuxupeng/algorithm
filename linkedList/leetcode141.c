#include <stdio.h>
#include <stdbool.h>
  struct ListNode {
      int val;
      struct ListNode *next;
  };

bool hasCycle(struct ListNode *head) {
    if(head==NULL || head->next==NULL)
        return false;
    struct ListNode *slow=head;
    struct ListNode *fast=head->next;
    while(slow!=fast){
        if(fast==NULL || fast->next==NULL)
            return false;
        slow=slow->next;
        fast=fast->next->next;
    }
    return true;
}
int main(){
    struct ListNode node1,node2,node3,node4;
    node1.val=3;
    node1.next=&node2;
    node2.val=2;
    node2.next=&node3;
    node3.val=0;
    node3.next=&node4;
    node4.val=-4;
    node4.next=&node2;
    bool b=hasCycle(&node1);
    printf("%d \n",b);
    return 1;

}

