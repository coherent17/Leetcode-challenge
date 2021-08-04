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

//time complexity:O(logn)
bool binary_search(int *array, int left, int right, int number){
    while(left<=right){
        //midpoint index:
        int mid=left+(right-left)/2;

        if(array[mid]==number) return true;
        else if(array[mid]>number) right=mid-1;
        else left=mid+1;
    }
    return false;
}

bool isPowerOfTwo(int n){
    if(n<=0) return false;
    int table[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536
    ,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728
    ,268435456,536870912,1073741824,};
    return binary_search(table, 0, 30, n);
}