int cmp(void *a, void *b){
    return (*((int **)b))[1] - (*((int **)a))[1];
}

int min(int a, int b){
    return a < b ? a : b;
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize){
    qsort(boxTypes, boxTypesSize, sizeof(int *), cmp);
    int res = 0;
    
    for(int i = 0; i < boxTypesSize; i++){
        int addNumber = min(truckSize, boxTypes[i][0]);
        res += addNumber * boxTypes[i][1];
        truckSize -= addNumber;
    }
    return res;
}