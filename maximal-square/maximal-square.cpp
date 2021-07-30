class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m][n];
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = matrix[i][j] - '0';
           
         
        
        //setting the base cases
        
       for(int i =1; i < m; i++){
           for(int j = 1; j< n; j++){
               if(matrix[i][j] == '1'){
                  
                   
                   if(dp[i-1][j] && dp[i-1][j-1] && dp[i][j-1])
                       dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                   
                   
               }
           }
       }
        
        int ans = 0;
        for(int i = 0;i< m; i++){
            for(int j = 0; j < n; j++)
                ans = max(ans, dp[i][j]);
        }
        
        return ans*ans;
        
    }
};