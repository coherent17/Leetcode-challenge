class Solution {
public:
    int minDeletions(string s) {
        int frequency[26] = {0};
        for(int i = 0; i < s.length(); i++){
            frequency[s[i]-'a']++;
        }
        unordered_set<int> us;
        int res = 0;
        for(int i = 0; i < 26; i++){
            if(frequency[i] != 0 && !us.count(frequency[i])){
                us.insert(frequency[i]);
            }
            else{
                while(frequency[i] > 0){
                    frequency[i]--;
                    res++;
                    if(!us.count(frequency[i])){
                        us.insert(frequency[i]);
                        break;
                    }
                }
            }
        }
        return res;
    }
};