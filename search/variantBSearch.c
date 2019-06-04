#include <stdio.h>
/**
 在一个有序数组种寻找第一个等于给定值的下标
 * */
int firstEqual(int *arr,int n,int value){
    int low=0;
    int high=n-1;
    int middle;
    while(low<=high){
       middle=low+((high-low)>>1);
       if(arr[middle]>value)
	  high=middle-1;
       else if(arr[middle]<value)
	  low=middle+1;
       else
	  if(middle==0)
              return 0;
          else if(arr[middle-1]==value)
	      high=middle-1;
          else
              return middle;
    }
    return -1;
}
/*
 * 在一个有序数组中寻找最后一个等于给定值的下标
 */
int lastEqual(int *arr,int n,int value){
    int low=0;
    int high=n-1;
    int middle;
    while(low<=high){
       middle=low+((high-low)>>1);
       if(arr[middle]>value)
	  high=middle-1;
       else if(arr[middle]<value)
	  low=middle+1;
       else
	  if(middle==n-1)
              return middle;
          else if(arr[middle+1]==value)
	      low=middle+1;
          else
              return middle;
    }
    return -1;
}
/*
 * 查找第一个大于等于给定值的元素
 */
int firstGreater(int *arr,int n,int value){
    int low=0;
    int high=n-1;
    int middle;
    while(low<=high){
       middle=low+((high-low)>>1);
       if(arr[middle]<value)
	   low=middle+1;
       else if(middle==0 || arr[middle-1]<value)
           return arr[middle];
       else 
           high=middle-1;
    }
}
/*
 * 查找最后一个小于等于给定值的元素
 */
int lastLess(int *arr,int n,int value){
    int low=0;
    int high=n-1;
    int middle;
    while(low<=high){
       middle=low+((high-low)>>1);
       if(arr[middle]>value)
	   high=middle-1;
       else if(middle==n-1 || arr[middle+1]>value)
           return arr[middle];
       else 
           low=middle+1;
    }
}

int main(){
    int arr[10]={1,3,4,5,6,8,8,8,11,18};
    printf("first value %d is in [%d]\n",8,firstEqual(arr,10,8));
    printf("last value %d is in [%d]\n",8,lastEqual(arr,10,8));
    printf("first greater %d is %d\n",9,firstGreater(arr,10,9));
    printf("last less %d is %d\n",9,lastLess(arr,10,9));


}
