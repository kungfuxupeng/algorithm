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


bool isValid(char * s){
    int i=0;
    bool returnValue=true;
    while(s[i]!=0){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            push(s[i]);
        }else if(s[i]==')' || s[i]==']' || s[i]=='}'){
            char c=pop();
            if(c==0)
                return false;

            if((s[i]==')' && c=='(') || (s[i]==']' && c=='[') || (s[i]=='}' && c=='{')){
                i++;
                continue;
            }else{
                return false;
            }
        }
        i++;
    }
    if(pop()==0)
        return true;
    return false;

}


int main(){
   char *s="{[]}";
   bool b=isValid(s);
   printf("%d\n",b);
}

