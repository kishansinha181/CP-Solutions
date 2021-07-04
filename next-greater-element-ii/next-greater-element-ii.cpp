class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> nge(n);
        for(int i = 2*n - 1; i>=0; i--){
            while(!s.empty() && nums[i%n] >= s.top())
                s.pop();
           
            
            if(i < n){
                if(s.empty())
                    nge[i] = -1;
                else
                    nge[i] = s.top();
            }
            s.push(nums[i%n]);
            
        }
        return nge;
        
    }
};