#include <stdio.h>

int mySqrt(int);

int main(){
    printf("%d",mySqrt(2147395600));
    return 0;
}

int mySqrt(int x){
    if(x==0) return 0;
    else if(x==1) return 1;

    int i;
    for(i=1;i<=x;i++){
        //since i*i might overflow
        if(i>x/i) break;
    }
    return i-1;
}