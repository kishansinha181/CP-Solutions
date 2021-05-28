class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> oh;
        for(auto it : nums) oh[it]++;
        int sum = 0;
        for(auto it: nums){
            if(oh[it]==1)
                sum+=it;
            
        }
        return sum;
        
    }
};