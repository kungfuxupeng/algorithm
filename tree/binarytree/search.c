#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Note{
  int data;
  struct Note *left;
  struct Note *right;
};  
struct Note *tree;
void btinsert(int value){
  if(tree==NULL){
    tree=(struct Note*)malloc(sizeof(struct Note));
    tree->data=value;
    printf("tree is:%p\n",tree);
    printf("插入根节点的数字是：%d\n",value);
    return;
  }
  struct Note* p=tree;
  while(p!=NULL){
    if(value<p->data){
      if(p->left!=NULL)
        p=p->left;
      else{
        struct Note *p_left=(struct Note*)malloc(sizeof(struct Note));
        p_left->data=value;
	p->left=p_left;
	printf("插入到了左节点，数字是：%d，其上级节点的值是：%d\n",value,p->data);
	return;
      }
    }else{
      if(p->right!=NULL)
        p=p->right;
      else{
        struct Note *p_right=(struct Note*)malloc(sizeof(struct Note));
        p_right->data=value;
        p->right=p_right;
	printf("插入到了右节点，数字是：%d，其上级节点的值是：%d\n",value,p->data);
        return;
      }

    }
  }
}   
//遍历

void preorder(struct Note *tree){
  if(tree==NULL)
    return;
  printf("%d,\n",tree->data);
  preorder(tree->left);
  preorder(tree->right);
}
// 查找
void search(int value){
  struct Note *note=tree;
  while(note!=NULL){
    if(value==note->data){
      printf("已经找到%d\n",note->data);
      return;
    }else if(value<note->data){
      note=note->left;
    }else{
      note=note->right;
    }
  }
  printf("没有找到%d\n",value);
}
//删除
void delete(int value){
  struct Note *note=tree;
  struct Note *lastNote=tree;
  int flag=0;//0是左边，1是右边
  while(note!=NULL){
    if(value<note->data){
      lastNote=note;
      note=note->left;
      flag=0;
    }else if(value>note->data){
      lastNote=note;
      note=note->right;
      flag=1;
    }else{
      printf("已经找到%d,并删除\n",note->data);
      if(note->left==NULL && note->right==NULL){
        if(note==tree)
	  tree=NULL;
	else if(flag==0)
	  lastNote->left=NULL;
	else
	  lastNote->right=NULL;
      }else if(note->left==NULL){
        if(note==tree)
	  tree=note->right;	
	else if(flag==0)
	  lastNote->left=note->right;
	else
	  lastNote->right=note->right;
      }else if(note->right==NULL){
        if(note==tree)
          tree=note->left;
        else if(flag==0)
          lastNote->left=note->left;
        else
          lastNote->right=note->left;
      }else{
        struct Note *rlNote=note->right;
	struct Note *sNote=note->right;
	while(sNote->left!=NULL){
          rlNote=sNote;
	  sNote=sNote->left;
	}
	if(note==tree)
	  tree=sNote;
	else if(flag==0)
	  lastNote->left=sNote;
	else
	  lastNote->right=sNote;

	sNote->left=note->left;
	if(sNote!=note->right){
	  sNote->right=note->right;
	  rlNote->left=NULL;
	}
	note=NULL;
      }

      return;
    }
  }
  printf("无法删除，没有找到%d\n",value);
}
void main(){
  int num[11]={3,5,4,6,8,9,20,1,10,3,6};
  
  for(int i=0;i<11;i++){
    btinsert(num[i]);
  }
  printf("tree end is:%p\n",tree);
  preorder(tree);
  search(20);
  search(3);
  search(100);
  delete(1000);
  delete(1);
  delete(6);
  preorder(tree);
  delete(8);
  preorder(tree);
}
