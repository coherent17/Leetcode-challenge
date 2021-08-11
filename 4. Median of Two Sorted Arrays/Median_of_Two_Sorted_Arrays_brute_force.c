#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int *, int, int *, int);

int main(){
    int nums1[]={0,0,0,0,0};
    int nums2[]={-1,0,0,0,0,0,1};
    float result;
    result=findMedianSortedArrays(nums1,sizeof(nums1)/sizeof(int),nums2,sizeof(nums2)/sizeof(int));
    printf("%.5f\n",result);
    return 0;
}

//time complexity:O(m+n), space complexity:O(m+n)
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if(nums1Size==0 && nums2Size==1) return nums2[0];
    if(nums1Size==1 && nums1Size==0) return nums1[0];
    else{
        int *temp=malloc((nums1Size+nums2Size)*sizeof(int));
        int nums1ptr=0,nums2ptr=0;

        //merge two sorted -array
        while(nums1ptr<nums1Size && nums2ptr<nums2Size){
            if(nums1[nums1ptr]<nums2[nums2ptr]){
                temp[nums1ptr+nums2ptr]=nums1[nums1ptr];
                nums1ptr++;
            }
            else{
                temp[nums1ptr+nums2ptr]=nums2[nums2ptr];
                nums2ptr++;
            }
        }

        //copy the rest of the array
        if(nums1ptr==nums1Size && nums2ptr<nums2Size){
            while(nums2ptr<nums2Size){
                temp[nums1ptr+nums2ptr]=nums2[nums2ptr];
                nums2ptr++;
            }
        }
        else if(nums1ptr<nums1Size && nums2ptr==nums2Size){
            while(nums1ptr<nums1Size){
                temp[nums1ptr+nums2ptr]=nums1[nums1ptr];
                nums1ptr++;
            }
        }

        //deal with the median of the merged array
        if((nums1Size+nums2Size)%2==0){
            float result=temp[(nums1Size+nums2Size)/2] + temp[(nums1Size+nums2Size)/2-1];
            free(temp);
            return result/2;
        }
        else{
            float result=temp[(nums1Size+nums2Size-1)/2];
            free(temp);
            return result;
        }
    }
}