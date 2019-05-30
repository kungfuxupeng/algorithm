#include <stdio.h>
#include <stdbool.h>

void sort(int *head,int count){
    int temp;
    int k=0;
    bool flag;
    for(int i=0;i<count-1;i++){
	flag=false;
        for(int j=0;j<count-1-i;j++){
	     k++;
	     if(head[j]>head[j+1]){
                 temp=head[j];
		 head[j]=head[j+1];
		 head[j+1]=temp;
		 flag=true;
	     }
	}
	if(!flag)
	   break;
    }
    printf("K=%d\n",k);
}

int main(){
  int arr[6] ={3,2,1,6,4,5};
  int *p;
  p=arr;

  for(int i=0;i<6;i++){
      printf("%d",*(p+i));
  }
  printf("\n");
  sort(p,6);

  for(int i=0;i<6;i++){
      printf("%d",arr[i]);
  }
  printf("\n");

}
