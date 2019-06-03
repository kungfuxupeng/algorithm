#include <stdio.h>
int search(int *arr,int low,int high,int value);
int bsearch(int *arr,int n,int value){
    return search(arr,0,n-1,value);
}

int search(int *arr,int low,int high,int value){
    int middle=low+((high-low)>>1);
    if(value==arr[middle])
        return middle;
    if(value>arr[middle])
	search(arr,++middle,high,value);
    else
	search(arr,low,--middle,value);
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    printf("%d在数组中的位置是：%d\n",4,bsearch(arr,10,4));
    return 1;
}
