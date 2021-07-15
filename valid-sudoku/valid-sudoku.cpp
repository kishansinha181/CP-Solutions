class Solution {
public:
    
    bool isValid(int row, int col, char num, vector<vector<char>> board ){
        for(int i = 0; i< 9; i++ ){
            if(board[row][i] == num)
                return false;
            if(board[i][col] == num)
                return false;
            if(board[(row/3)*3 + i/3][(col/3)*3 + i%3] == num)
                return false;
            
            
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j]!='.'){
                    char c = board[i][j];
                    board[i][j] = '.';
                    if(!isValid(i,j,c, board))
                        return false;
                else
                    continue;
                    board[i][j] = c;
                }
        }
    }
        return true;
    }                      
};