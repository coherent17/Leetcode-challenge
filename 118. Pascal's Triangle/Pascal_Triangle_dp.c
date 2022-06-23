int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    int **dp = malloc(sizeof(int *) * numRows);
    for(int i = 0; i < numRows; i++){
        (*returnColumnSizes)[i] = i + 1; 
        dp[i] = malloc(sizeof(int ) * (i + 1));
        dp[i][0] = 1;
        dp[i][i] = 1;
        for(int j = 1; j < i; j++){
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp;
}