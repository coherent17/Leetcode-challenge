class Solution {
public:
    int minDeletions(string s) {
        int frequency[26] = {0};
        for(int i = 0; i < s.length(); i++){
            frequency[s[i]-'a']++;
        }
        priority_queue <int> pq;
        int res = 0;
        for(int i = 0; i < 26; i++){
            if(frequency[i] != 0) pq.push(frequency[i]);
        }
        
        while(pq.size() > 1){
            int popElement = pq.top();
            pq.pop();
            if(popElement == pq.top()){
                if(popElement - 1 > 0){
                    pq.push(popElement - 1);
                }
                res++;
            }
        }
        
        return res;
    }
};