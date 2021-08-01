#include <stdio.h>

int mySqrt(int);

int main(){
    printf("%d",mySqrt(2147395599));
    return 0;
}

int mySqrt(int x){
    //using binary search to find the element a between 0~x

    if(x==0) return 0;
    if(x==1) return 1;

    int left=0,right=x;
    int answer=1;
    while(left<=right){
        int mid=left+(right-left)/2;

        //if x is a square number
        if(mid == x/mid) return mid;

        //if mid * mid is greater than x, set rightend as mid-1
        else if(mid > x/mid){
            right=mid-1;
        }

        //if mid * mid is smaller than x, set leftend as mid+1, and store the possible answer
        else{
            answer=mid;
            left=mid+1;
        }
    }
    return answer;
}