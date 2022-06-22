//F(i) = the maximum sum of subarray include index i
//F(i + 1) = max(F(i) + array[i + 1], array[i + 1])
//result to store the max sum of subarray so far

//Base Case:
//F(0) = array[0]

int max(int a, int b){
	return a > b ? a : b;
}

int maxSubArray(int* nums, int numsSize){
	int *dp = malloc(sizeof(int) * numsSize);
	dp[0] = nums[0];
	int result = dp[0];
	for(int i = 1; i < numsSize; i++){
		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		result = max(result, dp[i]);
	}
	free(dp);
	return result;
}

int maxSubArray(int* nums, int numsSize){
	int dp0 = nums[0];
	int result = dp0;
	for(int i = 1; i < numsSize; i++){
		int dp1 = max(dp0 + nums[i], nums[i]);
		result = max(result, dp1);
		dp0 = dp1;
	}
	return result;
}