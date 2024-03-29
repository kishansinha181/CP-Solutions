class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int curr_sum = 0;
        int best_sum = INT_MIN;
        for(int i =0;i < nums.size(); i++){
            
            curr_sum = max(curr_sum + nums[i], nums[i]);
            best_sum = max(best_sum, curr_sum);
        
        }
        
        return best_sum;
    }
};