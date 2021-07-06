class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0){
                    dp[i][j]=INT_MAX;
                }
                else if(j==0){
                    dp[i][j]=INT_MAX;
                }
                else if(i==1&&j==1){
                    dp[i][j]=grid[0][0];
                }
                else{
                    dp[i][j]=grid[i-1][j-1]+min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};