int getMaximumGenerated(int n){
    if(n == 0) return 0;
    else if(n == 1 || n == 2) return 1;
    int result = 1; 
    int *dp = malloc(sizeof(int) * (n + 1));
    
    //Base Case:
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 1; i <= n / 2; i++){
        if(2 * i <= n){
            dp[2 * i] = dp[i];
            result = dp[2 * i] > result ? dp[2 * i] : result;
        }
        if(2 * i + 1 <= n){
            dp[2 * i + 1] = dp[i] + dp[i + 1];
            result = dp[2 * i + 1] > result ? dp[2 * i + 1] : result;
        }
    }
    return result;
}