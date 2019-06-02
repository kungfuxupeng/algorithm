#include <stdio.h>
#include <stdbool.h>

int partition(int *arr,int p,int r){
    int i=p,j=p;
    int temp;
    int pivot=arr[r];
    for(;j<r;j++){
        if(arr[j]<=pivot){
	    if(i!=j){
                temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	    }
            i++;
        }
    }
    if(pivot>arr[i])
       return r;
    else{
        arr[r]=arr[i];
	arr[i]=pivot;
	return i;
    }
}

void sort_c(int *arr,int p,int r){
    if(p>=r)
	return;
    int q=partition(arr,p,r);
    sort_c(arr,p,q-1);
    sort_c(arr,q+1,r);
}

void sort(int *arr,int count){
   sort_c(arr,0,count-1);
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
