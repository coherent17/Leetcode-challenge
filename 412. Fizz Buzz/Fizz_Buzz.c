char ** fizzBuzz(int n, int* returnSize){
    *returnSize = n;
    
    char **res = malloc(sizeof(char *) * n);
    for(int i = 0; i < n; i++){
        res[i] = malloc(sizeof(char) * 9);
    }
    
    for(int i = 1; i <= n; i++){
        if(i % 3 == 0 && i % 5 == 0)    sprintf(res[i - 1], "FizzBuzz");
        else if(i % 3 == 0)             sprintf(res[i - 1], "Fizz");
        else if(i % 5 == 0)             sprintf(res[i - 1], "Buzz");
        else                            sprintf(res[i - 1], "%d", i);
    }
    return res;
}