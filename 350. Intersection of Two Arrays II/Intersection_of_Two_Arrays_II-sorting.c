int cmp(void *a, void *b){
    return *(int *)a - *(int *)b;
}


int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    
    int size = nums1Size > nums2Size ? nums1Size : nums2Size;
    int *res = malloc(sizeof(int) * size);
    int index = 0;
    
    //sort both array in non-decreasing order
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
        
    int i = 0;
    int j = 0;
    while(i < nums1Size && j < nums2Size){
        if(nums1[i] == nums2[j]){
            res[index++] = nums1[i];
            i++;
            j++;
        }
        else if(nums1[i] > nums2[j]){
            j++;
        }
        else if(nums1[i] < nums2[j]){
            i++;
        }
    }
    *returnSize = index;
    return res;
}