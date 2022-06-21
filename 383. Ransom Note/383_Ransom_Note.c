bool canConstruct(char * ransomNote, char * magazine){
	int charTable[26]={0};
	for(int i = 0; i < strlen(magazine); i++){
		charTable[magazine[i]-'a']++;
	}

	for(int i = 0; i < strlen(ransomNote); i++){
		charTable[ransomNote[i]-'a']--;
		if(charTable[ransomNote[i]-'a'] < 0) return false;
	}
	return true;
}