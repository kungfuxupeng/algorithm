#include <stdio.h>

int bsearch(int *arr,int n,int value){
    int low=0;
    int high=n-1;
    int middle;
    while(low<=high){
       middle=low+(high-low)/2;
       if(value==arr[middle])
	   return middle;
       else if(value>arr[middle])
	   low=++middle;
       else
	   high=--middle;
    }
    return -1;
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    printf("%d在数组中的位置是：%d\n",4,bsearch(arr,10,4));
}
