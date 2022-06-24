class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        //[1] : true, [2] : false
        if(target.size() == 1) return target[0] == 1;
        
        priority_queue <int> pq;
        unsigned long long int sum = 0;
        for(int i = 0; i < (int)target.size(); i++){
            pq.push(target[i]);
            sum += target[i];
        }
        
        while(1){
            int x = pq.top();
            
            //if the maximum element in the priority queue == 1 : end
            if(x == 1) return true;
            
            pq.pop(); 
            if(sum - x == 1) return true;
            
            if(x % (sum - x) == 0 || x % (sum - x) == x){
                return false;
            }
            
            pq.push(x % (sum - x));
            sum -= x - (x % (sum - x));
        }
        return true;
    }
};