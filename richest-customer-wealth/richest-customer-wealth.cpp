class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        vector<int> sum;
        for(int i = 0; i < accounts.size(); i++){
            sum.push_back(accumulate(accounts[i].begin(), accounts[i].end(), 0));
        }
        return *max_element(sum.begin(), sum.end());
        
    }
};