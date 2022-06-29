int cmp(void *a, void *b){
    //if the height is the same, sort by k in increasing order
    if( (*((int **)a))[0] == (*((int **)b))[0] ){
        return (*((int **)a))[1] - (*((int **)b))[1];
    }
    
    //sort by height in decreasing order
    return (*((int **)b))[0] - (*((int **)a))[0];
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = peopleSize;
    *returnColumnSizes = malloc(sizeof(int) * peopleSize);
    int **res = malloc(sizeof(int *) * peopleSize);
    for(int i = 0; i < peopleSize; i++){
        res[i] = malloc(sizeof(int ) * 2);
        (*returnColumnSizes)[i] = 2;
    }
    
    qsort(people, peopleSize, sizeof(int *), cmp);
    for(int i = 0; i < peopleSize; i++){
        
        //move space for the upcoming people
        for(int j = i; j > people[i][1]; j--){
            res[j] = res[j - 1];
        }
        
        //insert people with index = people[i][1]
        res[people[i][1]] = people[i];
    }
    return res;
}