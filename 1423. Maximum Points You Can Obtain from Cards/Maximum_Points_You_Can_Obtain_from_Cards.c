//Time Complexity: O(n^2)

int maxScore(int* cardPoints, int cardPointsSize, int k){
    if(k == cardPointsSize){
        int res = 0;
        for(int i = 0; i < cardPointsSize; i++){
            res += cardPoints[i];
        }
        return res;
    }
    
    int res = 0;
    for(int i = 0; i <=k; i++){
        int sum = 0;

        // 0 3
        if(i == 0){
            for(int j = 0; j < k; j++){
                sum += cardPoints[cardPointsSize - 1 - j];
            }
            res = sum > res ? sum : res;
        }
        

        // 3 0
        else if(i == k){
            for(int j = 0; j < k; j++){
                sum += cardPoints[j];
            }
            res = sum > res ? sum : res;
        }
        
        // 1 2
        // 2 1
        else{
            for(int j = 0; j < i; j++){
                sum += cardPoints[j];
            }
            for(int j = 0; j < k - i; j++){
                sum += cardPoints[cardPointsSize - 1 - j];
            }
            res = sum > res ? sum : res;
        }
    }
    return res;
}