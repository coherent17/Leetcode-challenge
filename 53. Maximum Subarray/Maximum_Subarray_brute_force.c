int maxSubArray(int* nums, int numsSize){
	int result = INT_MIN;
	for(int size = 0; size < numsSize; size++){
		for(int i = 0;i + size < numsSize;i++){
			int temp_sum = 0;
			for(int j = i; j <= i + size; j++){
				temp_sum += nums[j];
			}
			result = temp_sum > result ? temp_sum : result;
		}
	}
	return result;
}