#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void sort_c(int *arr,int start,int end);
void merge(int *arr,int start,int middle,int end);

void sort(int *arr,int count){
    sort_c(arr,0,count-1);
}
void sort_c(int *arr,int start,int end){
    if(start>=end)
	return;
    int middle=(start+end)/2;
    sort_c(arr,start,middle);
    sort_c(arr,middle+1,end);
    merge(arr,start,middle,end);
}
void merge(int *arr,int start,int middle,int end){
    int *temp=(int *)malloc(sizeof(int)*(end-start+1));
    int ap=start,bp=middle+1;
    int i=0;
    while(ap<=middle && bp<=end){
       if(arr[ap]>arr[bp]){
          temp[i++]=arr[bp++];
       }else{
          temp[i++]=arr[ap++];
       }
    }
    if(bp<=end){
        for(int j=bp;j<=end;i++,j++){
            temp[i]=arr[j];
	}
    }else{
	for(int j=ap;j<=middle;i++,j++){
            temp[i]=arr[j];
        }
    }
    for(int i=0;i<=end-start;i++){
        arr[start+i]=temp[i];
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
  sort(p,6);

  for(int i=0;i<6;i++){
      printf("%d",arr[i]);
  }
  printf("\n");

}
