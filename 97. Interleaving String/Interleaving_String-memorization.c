//return the substring of s start from s[startIndex]
char *subString(char *s, int startIndex){
    int len = strlen(s) - startIndex;
    char *ret = malloc(sizeof(char) * (len + 1));
    strncpy(ret, &s[startIndex], len);
    ret[len] = '\0';
    return ret;
}

bool helper(char *s1, int i, char *s2, int j, char *s3, int k, int **memo){
    if(i == strlen(s1)){
        return !strcmp(subString(s2, j), subString(s3, k));
    }
    
    if(j == strlen(s2)){
        return !strcmp(subString(s1, i), subString(s3, k));
    }
    
    if(memo[i][j] >= 0){
        return memo[i][j];
    }
    
    //if the current result is matched with s3, the final result is dependent only on remaining s1 & s2
    bool ret = false;
    if(s1[i] == s3[k] && helper(s1, i + 1, s2, j, s3, k + 1, memo)){
        ret = true;
    }
    
    if(s2[j] == s3[k] && helper(s1, i, s2, j + 1, s3, k + 1, memo)){
        ret = true;
    }
    memo[i][j] = ret;
    return ret;
}

bool isInterleave(char * s1, char * s2, char * s3){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    
    if(len1 + len2 != len3) return false;
    
    //compare s2 with s3 if s1 = ""
    if(len1 == 0 && len2 != 0){
        bool ret = !strncmp(s2, s3, len3);
        return ret;
    }
    
    //compare s1 with s3 if s2 = ""
    else if(len1 != 0 && len2 == 0){
        bool ret = !strncmp(s1, s3, len3);
    }
    
    //compare s3 with "" if s1 = s2 = ""
    else if(len1 == 0 && len2 == 0){
        return len3 == 0;
    }
    
    //allocate memory for memorization 2D array
    int **memo = malloc(sizeof(int *) * len1);
    for(int i = 0; i < len1; i++){
        memo[i] = malloc(sizeof(int) * len2);
    }
    
    //init memoArray
    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            memo[i][j] = -1;
        }
    }

    return helper(s1, 0, s2, 0, s3, 0, memo);
}