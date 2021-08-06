class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX;
        int ans = 0;
        for(auto it: prices){
            mn = min(mn, it);
            ans = max(ans, it - mn);
        }
        return ans;
 
    }
};