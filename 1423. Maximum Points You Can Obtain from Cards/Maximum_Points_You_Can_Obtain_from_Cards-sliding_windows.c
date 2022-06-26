int maxScore(int* cardPoints, int cardPointsSize, int k){
    if(k == cardPointsSize){
        int res = 0;
        for(int i = 0; i < cardPointsSize; i++){
            res += cardPoints[i];
        }
        return res;
    }
    
    int leftWindow = 0;
    int rightWindow = cardPointsSize - 1 - k;
    
    int res = 0;
    int currentSum = 0;
    
    //calculate the initial sum
    for(int i = rightWindow + 1; i < cardPointsSize; i++){
        currentSum += cardPoints[i];
        res = currentSum;
    }
    
    //start sliding window
    while(rightWindow <= cardPointsSize - 2){
        leftWindow += 1;
        rightWindow += 1;
        currentSum += -cardPoints[rightWindow] + cardPoints[leftWindow - 1];
        res = currentSum > res ? currentSum : res;
    }
    return res;
}