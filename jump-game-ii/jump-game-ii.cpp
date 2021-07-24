class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int dp[n] ;
        int inf = 20000;
        memset(dp,inf, sizeof(dp));
        dp[0] = 0;
        for(int i = 1; i <n; i++){
            for(int j = 0; j<=i-1; j++){
                if(j + nums[j] >= i && dp[j]!=INT_MAX)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        // for(int i = 0; i < n ; i++)
        //     cout<<dp[i] <<" ";
        return dp[n-1];
    }
};