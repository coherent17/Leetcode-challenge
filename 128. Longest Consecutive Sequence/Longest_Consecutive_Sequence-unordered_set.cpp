class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
    
        unordered_set<int> us(nums.begin(),nums.end());
        
        int ret = 1;
        for(int i = 0; i < nums.size(); i++){
            if(us.find(nums[i]-1) != us.end()) continue;
            int count = 1;
            int curr = nums[i];
            while(us.find(curr+1) != us.end()){
                count++;
                curr++;
            }
            ret = ret > count ? ret : count;
        }
        return ret;
    }
};