int cmp(void *a, void *b){
    return *(int *)a - *(int *)b;
}

int max(int a, int b){
    return a > b ? a : b;
}

int maxArea(int h, int w, int* horizontalCuts, int horizontalCutsSize, int* verticalCuts, int verticalCutsSize){
    qsort(horizontalCuts, horizontalCutsSize, sizeof(int), cmp);
    qsort(verticalCuts, verticalCutsSize, sizeof(int), cmp);
    
    //check for the horizontal boundary:
    int max_height_gap = max(horizontalCuts[0], h - horizontalCuts[horizontalCutsSize - 1]);

    //check the gap between two horizontal slices
    for(int i = 1; i < horizontalCutsSize; i++){
        max_height_gap = max(max_height_gap, horizontalCuts[i] - horizontalCuts[i - 1]);
    }
    
    //check for the vetical boundary:
    int max_width_gap = max(verticalCuts[0], w - verticalCuts[verticalCutsSize - 1]);
    
    //check the gap between two vertical slices
    for(int i = 1; i < verticalCutsSize; i++){
        max_width_gap = max(max_width_gap, verticalCuts[i] - verticalCuts[i - 1]);
    }
    
    int mod = 1e9 + 7;
    long long area = (long long)(max_height_gap) * (long long)(max_width_gap);
    return (int)(area % mod);
}