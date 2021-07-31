#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int);

int main(){
    printf("%d",isPalindrome(121));
    return 0;
}

bool isPalindrome(int x){
    if(x<0) return false;
    if(x>=0 && x<=9) return true;
    else{
        int digit[13];
        int count=0;
        while(x>=10){
            digit[count]=x%10;
            x/=10;
            count+=1;
        }
        digit[count]=x;
        for(int i=0;i<=count/2+1;i++){
            if(digit[i]!=digit[count-i]) return false;
        }
    }
    return true;
}