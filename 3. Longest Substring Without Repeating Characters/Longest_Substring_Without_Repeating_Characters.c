int lengthOfLongestSubstring(char * s){
    if(strlen(s) == 0) return 0;
    if(strlen(s) == 1) return 1;
    
    int Table[128] = {0};
    Table[s[0]] = 1;
    int temp = 1;
    int res = 1;
    
    int leftWindow = 0;
    int rightWindow = 1;
    
    for(int i = 1; i < strlen(s); i++){
        if(Table[s[i]] == 0){
            Table[s[i]] = 1;
            rightWindow = i;
            temp++;
            res = temp > res ? temp : res;
            continue;
        }
        else{
            for(int j = i - 1; j >= leftWindow; j--){
                if(s[j] == s[i]){
                    temp++;
                    temp -= j - leftWindow + 1;
                    for(int k = leftWindow; k < j; k++){
                        Table[s[k]] = 0;
                    }
                    leftWindow = j + 1;
                }
            }
        }
    }
    return res;
}