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

    int n_origin=n;

    while(n%2==0){
        n=n/2;
    }
    int multiple_2=n_origin/n;
    
    //reset the origin to new divisor
    n=n_origin;
    while(n%3==0){
        n=n/3;
    }
    int multiple_3=n_origin/n;

    n=n_origin;
    while(n%5==0){
        n=n/5;
    }
    int multiple_5=n_origin/n;
    
    return multiple_2*multiple_3*multiple_5==n_origin;
}