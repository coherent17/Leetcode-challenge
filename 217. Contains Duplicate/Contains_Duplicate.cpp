class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> us;
        for(int i = 0; i < (int)nums.size(); i++){
            if(!us.count(nums[i])){
                us.insert(nums[i]);
            }
            else return true;
        }
        return false;
    }
};