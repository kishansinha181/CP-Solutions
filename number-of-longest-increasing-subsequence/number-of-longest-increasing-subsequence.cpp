class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        pair<int,int>dp[n];
        dp[n-1]={1,1};
        for(int i=n-2;i>=0;i--)
        {
            int ele=nums[i];
            dp[i]={1,1};
            for(int j=i+1;j<n;j++)
            {
              if(nums[j]>ele)
              {
                  if(dp[i].first<dp[j].first+1)
                  {
                      dp[i].first=dp[j].first+1;
                      dp[i].second=dp[j].second;
                  }
                  else if(dp[i].first==dp[j].first+1)
                  {
                      dp[i].second+=dp[j].second;
                  }
              }
            }
        }

        int maxlen=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
          if(dp[i].first>maxlen)
          {
              maxlen=dp[i].first;
              ans=dp[i].second;
          }
          else if(dp[i].first==maxlen)
          {
              ans+=dp[i].second;
          }
        }
        return ans;
        
    }
};