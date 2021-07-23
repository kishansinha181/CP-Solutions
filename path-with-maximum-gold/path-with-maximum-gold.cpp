class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid){
        if(grid[i][j] == 0)
            return 0;
        int costAtcurrent = grid[i][j];
        
        grid[i][j] = 0;
        
        int op1= 0;
        int op2 = 0;
        int op3 = 0;
        int op4 = 0;
        
        if(i-1 >=0)
            op1 = dfs(i-1, j, m,n,grid);
        if(j-1 >=0)
            op2 = dfs(i, j-1, m,n,grid);
        if(i+1 <m)
            op3 = dfs(i+1, j, m,n,grid);
        if(j+1 <n)
            op4 = dfs(i, j+1, m,n,grid);
        
        grid[i][j] = costAtcurrent;
        
        return costAtcurrent + max(op1,max(op2,max(op3,op4)));
        
    }
    
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MIN;
        for(int i =0 ; i < m; i ++ ){
            for(int j = 0; j < n; j++){
                if(grid[i][j]!=0){
                    ans = max(ans, dfs(i,j,m,n,grid));
                }
            }
        }
        return ans;
    }
};