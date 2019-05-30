#include <stdio.h>
#include <stdbool.h>

void sort(int *head,int count){
    int temp;
    int k=0;
    for(int i=0;i<count-1;i++){
	temp=head[i];
	k=i;
        for(int j=i+1;j<count;j++){
	     if(head[j]<temp){
		 temp=head[j];
		 k=j;
	     }
	}
	head[k]=head[i];
	head[i]=temp;

    }
}

void sort2(int *head,int count){
   int k=0;
   int temp;
   for(int i=0;i<count-1;i++){
       k=i+1;
       temp=head[i+1];
       for(int j=i+1;j<count;j++){
           if(head[j]<temp)
	       k=j;
       }
       if(head[i]>head[k]){
           temp=head[i];
	   head[i]=head[k];
	   head[k]=temp;
       }
   }
}

int main(){
  int arr[6] ={3,2,1,6,4,5};
  int *p;
  p=arr;

  for(int i=0;i<6;i++){
      printf("%d",*(p+i));
  }
  printf("\n");
  sort2(p,6);

  for(int i=0;i<6;i++){
      printf("%d",arr[i]);
  }
  printf("\n");

}
