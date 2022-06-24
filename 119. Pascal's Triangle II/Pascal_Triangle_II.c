

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int **dp = malloc(sizeof(int *) * (rowIndex + 1));
    for(int i = 0; i <= rowIndex; i++){
        dp[i] = malloc(sizeof(int) * (i + 1));
    }
    
    dp[0][0] = 1;
    for(int i = 1; i <= rowIndex; i++){
        dp[i][0] = 1;
        dp[i][i] = 1;
        
        for(int j = 1; j < i; j++){
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    
    int *result = malloc(sizeof(int) * (rowIndex + 1));
    *returnSize = (rowIndex + 1);
    
    //copy the answer to result
    for(int i = 0; i <= rowIndex; i++){
        result[i] = dp[rowIndex][i];
    }
    return result;
}