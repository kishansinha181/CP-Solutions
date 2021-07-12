class Solution {
public:
    
     void dfs(int i, int j, int &m, int &n, vector<vector<char>>& grid) {
        if (grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0';
        
        if (i + 1 < m) {
            dfs(i+1, j, m, n, grid);
        }
        
        if (j + 1 < n) {
            dfs(i, j+1, m, n, grid);
        }
        
        if (i - 1 >= 0) {
            dfs(i-1, j, m, n, grid);
        }
        
        if (j - 1 >= 0) {
            dfs(i, j-1, m, n, grid);
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++ans;
                    dfs(i, j, m, n, grid);
                }
            }
        }
        
        return ans;
    }
};