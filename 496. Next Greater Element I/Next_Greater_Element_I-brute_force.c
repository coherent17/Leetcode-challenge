#include <stdio.h>
#include <stdlib.h>

int *nextGreaterElement(int *, int, int *, int, int *);

int main(){
    int nums1[] = {4, 1, 2};
    int nums2[] = {1, 3, 4, 2};
    int returnSize;
    int *result = NULL;
    result = nextGreaterElement(nums1, sizeof(nums1)/sizeof(int), nums2, sizeof(nums2)/sizeof(int), &returnSize);
    for (int i = 0; i < returnSize;i++){
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}

int searchIndex(int *nums2, int nums2Size, int value){
    for (int i = 0; i < nums2Size;i++){
        if(nums2[i]==value)
            return i;
    }
    return -1;
}

int NextGreaterElement(int *nums2, int nums2Size, int index, int value){
    for (int i = index + 1; i < nums2Size;i++){
        if(nums2[i]>value)
            return nums2[i];
    }
    return -1;
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *result = malloc(sizeof(int) * nums1Size);
    (*returnSize) = nums1Size;
    for (int i = 0; i < nums1Size;i++){
        int index = searchIndex(nums2, nums2Size, nums1[i]);
        result[i] = NextGreaterElement(nums2, nums2Size, index, nums1[i]);
    }
        return result;
}