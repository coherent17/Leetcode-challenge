#include <stdio.h>

int singleNumber(int *, int);

int main(){
    int nums[]={4,1,2,1,2};
    printf("%d",singleNumber(nums,sizeof(nums)/sizeof(int)));
    return 0;
}

//use bitwise XOR:
//since: a⊕0=a, a⊕a=0
//assume the array contain a,b,c three element:  array[]=[a,b,c,b,a]
//want to find out who is the one appear only once, XOR them all bitwisely
//a⊕b⊕c⊕b⊕a=(a⊕a)⊕(b⊕b)⊕c=0⊕0⊕c=c
//time complexity: O(n)

int singleNumber(int* nums, int numsSize){
    int value=nums[0];
    for(int i=1;i<numsSize;i++){
        value^=nums[i];
    }
    return value;
}