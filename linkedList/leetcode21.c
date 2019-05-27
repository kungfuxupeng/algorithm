#include <stdio.h>
  struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head;
    if(l1==NULL){
       head=l2;
       return head;
    }else if(l2==NULL){
       head=l1;
       return head;
    }
    struct ListNode* position; 
    
    if(l1->val > l2->val){
        head=l2;
        l2=l2->next;
    }
    else{
        head=l1;
        l1=l1->next;
    }
    position=head;
    
    while(1){
        if(l1==NULL){
            position->next=l2;
            break;
        }else if(l2==NULL){
            position->next=l1;
            break;
        }
        if(l1->val > l2->val){
            position->next=l2;
            l2=l2->next;
        }else{
            position->next=l1;
            l1=l1->next;
        }
         position=position->next;
    }                                                                                                     return head;
}
		
int main(){
   struct ListNode l11,l12,l13;
   l11.val=1;
   l11.next=&l12;
   l12.val=2;
   l12.next=&l13;
   l13.val=4;
   l13.next=NULL;

   struct ListNode l21,l22,l23;
   l21.val=1;
   l21.next=&l22;
   l22.val=3;
   l22.next=&l23;
   l23.val=4;
   l23.next=NULL;

  /* struct ListNode *l11,*l12,*l13;
   l11->val=1;
   l11->next=l12;
   l12->val=2;
   l12->next=l13;
   l13->val=4;
   l13->next=NULL;

   struct ListNode *l21,*l22,*l23;
   l21->val=1;
   l21->next=l22;
   l22->val=3;
   l22->next=l23;
   l23->val=4;
   l23->next=NULL;*/



   struct ListNode* head=mergeTwoLists(&l11,&l21);
   while(head!=NULL){
       printf("%d \n",head->val);
       head=head->next;
   }
   return 0;
}

