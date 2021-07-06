class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        bool flag = binary_search(nums.begin(), nums.end(), target);
        if(!flag)
            return {-1,-1};
        int idx1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
         int idx2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {idx1, idx2};
    }
};