#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void sort(int *arr,int n,int k){
     int *c=(int *)(malloc(sizeof(int)*k));
     int *r=(int *)(malloc(sizeof(int)*k));
     int *s=(int *)(malloc(sizeof(int)*n));
     for(int i=0;i<k;i++)
	 c[i]=0;
     for(int i=0;i<n;i++){
         c[arr[i]]++;
     }

     for(int i=0;i<k;i++)
	 r[i]=0;
     r[0]=c[0];
     for(int i=1;i<k;i++){
         r[i]=c[i]+r[i-1];
     }
     for(int i=0;i<n;i++){
       s[--r[arr[i]]]=arr[i];
     }
     for(int i=0;i<n;i++){
       arr[i]=s[i];
     }
}

int main(){
/**
 *需求：有8个人考试，只有0~5分，给八个人按分数大小排序
 *模拟大规模的考生考试排序，比如高考
 *或者给大规模的人群按年龄排序
 **/
    int arr[8]={2,5,3,0,2,3,0,3};
    int *p=arr;
    printf("unsort:\n");
    for(int i=0;i<8;i++){
       printf("%d \n",*(p+i));
    }
    sort(p,8,6);
    printf("sorted:\n");
    for(int i=0;i<8;i++){
       printf("%d \n",*(p+i));
    }

}
