#include <stdio.h>
#include <stdbool.h>

void sort(int *head,int count){
    int k=0;
    int temp;
    for(int i=1;i<count;i++){
        for(int j=0;j<i;j++){
	     if(head[i]<head[j]){
		//插入
		temp=head[i];
		for(int s=i;s>j;s--){
		    k++;
		    head[s]=head[s-1];
		}
		head[j]=temp;
		break;
	     }
	}
	printf("i=%d:\n",i);
	for(int i=0;i<6;i++){
            printf("%d,",head[i]);
        }
        printf("\n");

    }
    printf("K=%d\n",k);
}

void sort2(int *head,int count){
    int k=0;
    int temp;
    for(int i=1;i<count;i++){
	temp=head[i];
        for(int j=i-1;j>=0;j--){
	     if(temp>=head[j]){
	        head[j+1]=temp;
	        break;	
	     }
	     else{
		k++;
		head[j+1]=head[j];
		if(j==0)
		   head[j]=temp;
		continue;
             }
        }
        printf("i=%d:\n",i);
        for(int i=0;i<6;i++){
            printf("%d,",head[i]);
        }
        printf("\n");

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
  sort2(p,6);

  for(int i=0;i<6;i++){
      printf("%d",arr[i]);
  }
  printf("\n");

}
