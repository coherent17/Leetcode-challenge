#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPowerOfTwo(int);

int main(){
    printf("%d\n",isPowerOfTwo(1));
    printf("%d\n",isPowerOfTwo(16));
    printf("%d\n",isPowerOfTwo(3));
    printf("%d\n",isPowerOfTwo(4));
    printf("%d\n",isPowerOfTwo(5));
    return 0;
}

//time complexity:O(1)
bool isPowerOfTwo(int n){
    //do bitwise "and" operator between (n)_2 and (n-1)_2
    //ex:n=8(1000), n-1=7(0111):  1000 & 0111=0000=0_10, therefore, n=8 is the power of 2
    //ex:n=7(0111), n-1=6(0110):  0111 & 0110=0110=6_10, therefore, n=7 isn't the power of 2
    return (n>0)&& !(n&(n-1));
}