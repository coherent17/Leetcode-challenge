int max(int a, int b){
    return a > b ? a : b;
}

int candy(int* ratings, int ratingsSize){
    //record the minimum candies needed to satisfied only for left neighbor
    int *leftcmp = malloc(sizeof(int) * ratingsSize);

    //record the minimum candies needed to satisfied only for right neighbor
    int *rightcmp = malloc(sizeof(int) * ratingsSize);
    
    for(int i = 0; i < ratingsSize; i++){
        leftcmp[i] = 1;
        rightcmp[i] = 1;
    }
    
    for(int i = 1; i < ratingsSize; i++){
        if(ratings[i] > ratings[i-1]){
            leftcmp[i] = leftcmp[i-1] + 1;
        }
    }
    
    for(int i = ratingsSize - 2; i >= 0; i--){
        if(ratings[i] > ratings[i+1]){
            rightcmp[i] = rightcmp[i+1] + 1;
        }
    }
    
    //the minimum candies we need is to satisfied both left and right relation
    int ret = 0;
    for(int i = 0; i < ratingsSize; i++){
        ret += max(leftcmp[i], rightcmp[i]);
    }
    
    return ret;
}