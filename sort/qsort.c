#include <stdio.h>
#include <stdlib.h>
int arr[5]={20,10,58,63,15};
int compare(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int main(){
    for(int i=0;i<5;i++){
       printf("%d \n",arr[i]);
    }

    qsort(arr,5,sizeof(int),compare);
    printf("sorted:\n");
    for(int i=0;i<5;i++){
       printf("%d \n",arr[i]);
    }
    return 1;

}
