class Solution {
public:
    int dp[21][21];
    int maxValue(vector<int> nums, int i , int j ){
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
      
    dp[i][j] = max(nums[i] + min(maxValue(nums,i+2,j), maxValue(nums,i+1,j-1)),
                    nums[j] + min(maxValue(nums,i+1, j-1), maxValue(nums,i,j-2))
                  
                  );
        
        return dp[i][j];
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int x= accumulate(nums.begin(), nums.end(),0);
        int player1Val = maxValue(nums,0,nums.size()-1);
        if( player1Val >= x- player1Val )
            return true;
        return false;
    }
};