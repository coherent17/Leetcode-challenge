class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue <int> pq;
        int sum = 0;
        for(int i = 0; i < (int)target.size(); i++){
            pq.push(target[i]);
            sum += target[i];
        }
        
        while(1){
            int temp = pq.top();
            if(temp == 1) return true;
            pq.pop();
            
            if(temp - (sum - temp) <= 0) return false;
            
            pq.push(temp - (sum - temp));
            sum -= temp - (temp - (sum - temp));
        }
        return true;
    }
};