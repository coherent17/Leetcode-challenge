int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int size = nums1Size > nums2Size ? nums1Size : nums2Size;
    int *res = malloc(sizeof(int) * size);
    int index = 0;
    
    int frequencyTable[1001] = {0};
    
    for(int i = 0; i < nums1Size; i++){
        frequencyTable[nums1[i]]++;
    }
    
    for(int i = 0; i < nums2Size; i++){
        if(frequencyTable[nums2[i]] != 0){
            res[index++] = nums2[i];
            frequencyTable[nums2[i]]--;
        } 
    }
    
    *returnSize = index;
    return res;
}