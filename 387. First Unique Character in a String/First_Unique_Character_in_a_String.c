int firstUniqChar(char * s){
    if(strlen(s) == 0) return -1;
    int size = strlen(s);
    int frequency[26] = {0};
    
    for(int i = 0; i < size; i++){
        frequency[s[i] - 'a']++;
    }
    
    for(int i = 0; i < size; i++){
        if(frequency[s[i]-'a'] == 1) return i;
    }
    return -1;
}