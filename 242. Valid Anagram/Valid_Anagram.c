bool isAnagram(char * s, char * t){
    if(strlen(s) != strlen(t)) return false;
    
    int frequency[26] = {0};
    for(int i = 0; i < strlen(s); i++){
        frequency[s[i]-'a']++;
        frequency[t[i]-'a']--;
    }
    
    for(int i = 0; i < 26; i++){
        if(frequency[i] != 0) return false;
    }
    return true;
}