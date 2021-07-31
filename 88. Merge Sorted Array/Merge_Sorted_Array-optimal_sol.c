#include <stdio.h>

void merge(int*, int, int, int*, int, int);

int main(){
    int nums1[6]={1,2,3,0,0,0};
    int nums2[3]={2,5,6};
    merge(nums1, 6, 3, nums2, 3, 3);
    for(int i=0;i<6;i++){
        printf("%d ",nums1[i]);
    }
    return 0;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    //no element in nums2 array do nothing
    if(n==0) return;

    //no element in nums1, copy the element in nums2 to nums1 array
    if(m==0){
        for(int i=0;i<n;i++){
            nums1[i]=nums2[i];
        }
        return;
    }
    
    /*don't want to claim another temp array to store the element to avoid cover the nums1,
    since both arrays are sorted, we can compare the end of both array to test, and put the greater element into 
    the end of the nums1*/

    int ptr1=m-1,ptr2=n-1,index=m+n-1;
    while(ptr1>=0 && ptr2 >=0){
        //end of nums1 is greater than nums2
        if(nums1[ptr1] > nums2[ptr2]) nums1[index--]=nums1[ptr1--];
        
        else nums1[index--]=nums2[ptr2--];
    }
    //put the rest of nums2 array into nums1
    while(ptr2>=0){
            nums1[index--]=nums2[ptr2--];
        }
}