class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < (int)nums.size(); i++){
            pq.push(nums[i]);
        }
        while(k > 1){
            k--;
            pq.pop();
        }
        return pq.top();
    }
};