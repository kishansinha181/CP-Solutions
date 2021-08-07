class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, pair<int, pair<int, int>>> myMap;
        for(int i = 0;i < nums.size(); i++){
            if(myMap[nums[i]].first == 0)
                myMap[nums[i]].second.first = i;
                
            myMap[nums[i]].first ++;
            
            myMap[nums[i]].second.second = i;
        }
        
        int degree = 0;
        for(auto x: myMap) degree = max(degree, x.second.first);
        int ans = INT_MAX;
        for(auto x: myMap){
            if(x.second.first == degree)
                ans = min(ans, x.second.second.second - x.second.second.first +1);
            }
        return ans;
    }
};