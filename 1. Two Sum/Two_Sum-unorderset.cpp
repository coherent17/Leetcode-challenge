class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> my_unordered_map;
        for(int i = 0; i < nums.size(); i++){
            if(my_unordered_map.find(nums[i]) == my_unordered_map.end()){
                my_unordered_map[target - nums[i]] = i;
            }
            else{
                result.push_back(my_unordered_map[nums[i]]);
                result.push_back(i);
                return result;
            }
        }
        return result;
    }
};