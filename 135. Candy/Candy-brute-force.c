int candy(int* ratings, int ratingsSize){
    int *candies = malloc(sizeof(int) * ratingsSize);
    for(int i = 0; i < ratingsSize; i++){
        candies[i] = 1;
    }
    
    bool hasChange = true;
    while(hasChange){
        hasChange = false;
        for(int i = 0; i < ratingsSize; i++){
            if(i < ratingsSize - 1 && ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]){
                candies[i] = candies[i+1] + 1;
                hasChange = true;
            }
            if(i > 0 && ratings[i] > ratings[i-1] && candies[i] <= candies[i-1]){
                candies[i] = candies[i-1] + 1;
                hasChange = true;
            }
        }
    }
    int ret = 0;
    for(int i = 0; i < ratingsSize; i++){
        ret += candies[i];
    }
    return ret;
}