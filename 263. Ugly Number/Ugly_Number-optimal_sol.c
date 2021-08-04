#include <stdio.h>
#include <stdbool.h>

bool isUgly(int);

int main(){
    printf("%d\n",isUgly(6));  //true
    printf("%d\n",isUgly(8));  //true
    printf("%d\n",isUgly(14)); //false
    printf("%d\n",isUgly(1));  //true
    return 0;
}

bool isUgly(int n){
    if(n<=0) return false;
    if(n==1) return true;
    while(n%2==0) n/=2;
    while(n%3==0) n/=3;
    while(n%5==0) n/=5;
    return n==1;
}