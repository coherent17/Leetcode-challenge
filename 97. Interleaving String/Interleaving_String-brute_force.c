//TC = O(2^m * 2^n) = O(2^(m+n))
//SC = O(m + n)

bool helper(char *s1, int s1_index, char *s2, int s2_index, char *str, int strLen, char *s3){
    
    //recursion terminate condition: use all characters in s1 and s2 and form str == s3
    if(!strncmp(str, s3, strlen(s3)) && s1_index == strlen(s1) && s2_index == strlen(s2)){
        return true;
    }
    
    bool ret = false;
    
    //choose next character from s1 and append at the end of the str
    if(s1_index < strlen(s1)){
        str[strLen] = s1[s1_index];
        ret |= helper(s1, s1_index + 1, s2, s2_index, str, strLen + 1, s3);
    }
    
    //choose next character from s2 and append at the end of the str
    if(s2_index < strlen(s2)){
        str[strLen] = s2[s2_index];
        ret |= helper(s1, s1_index, s2, s2_index + 1, str, strLen + 1, s3);
    }
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
    char str[len3];
    memset(str, len3, '\0');
    return helper(s1, 0, s2, 0, str, 0, s3);
}