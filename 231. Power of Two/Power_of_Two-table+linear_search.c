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

//time complexity:O(n)
bool isPowerOfTwo(int n){
    if(n<=0) return false;
    int table[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536
    ,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728
    ,268435456,536870912,1073741824,};

    for(int i=0;i<31;i++){
        if(n==table[i]) return true;
    }
    return false;
}