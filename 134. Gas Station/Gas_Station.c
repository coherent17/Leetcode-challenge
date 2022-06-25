int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int sumOfDiff = 0;
    int result = 0;
    for(int i = 0; i < gasSize; i++){
        sumOfDiff += gas[i] - cost[i];
    }
    if(sumOfDiff < 0) return -1;
    
    else{
        int total = 0;
        for(int i = 0; i < gasSize; i++){
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                result = i + 1;
            }
        }
    }
    return result;
}