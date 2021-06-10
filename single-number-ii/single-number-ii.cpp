class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int mask  = 1<<i;
            int sum = 0;
            for(auto x: nums){
                if(x&mask)
                    sum++;
                
            }
            sum%=3;
            ans+=(1<<i)*sum;
            }
        
        return ans;
        
    }
};