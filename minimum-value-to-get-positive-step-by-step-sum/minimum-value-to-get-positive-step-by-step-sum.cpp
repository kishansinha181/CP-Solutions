class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = -1;
        int best = sum;
        for(auto x : nums){
            sum+=x;
            best = min(sum,best);
        }
        return -1*best;
    }
};