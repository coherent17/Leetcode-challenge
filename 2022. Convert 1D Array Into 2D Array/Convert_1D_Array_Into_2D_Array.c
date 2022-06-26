int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes){
    if(m * n != originalSize){
        *returnSize = 0;
        return NULL;
    }
    
    *returnSize = m;
    *returnColumnSizes = malloc(sizeof(int) * m);
    for(int i = 0; i < m; i++){
        (*returnColumnSizes)[i] = n;
    }
    
    int **result = malloc(sizeof(int *) * m);
    for(int i = 0; i < m; i++){
        result[i] = malloc(sizeof(int) * n);
    }
    
    int index = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            result[i][j] = original[index++]; 
        }
    }
    return result;
}