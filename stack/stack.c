#include <stdio.h>
#include <stdbool.h>
char str[100];
int n=100;
int count=0;
bool push(char c){
    if(count==n)
       return false;
    str[count]=c;
    count++;
    return true;
}
char pop(){
    if(count==0)
        return 0;
    count--;
    return str[count];
}
int main(){
    int i=0;
    while(true){
      i++;
      if(! push(i))
	 break;
    }
    while(true){
      char c=pop();
      if(c==0)
	 break;
      printf("%c \n",c);
    }

}
