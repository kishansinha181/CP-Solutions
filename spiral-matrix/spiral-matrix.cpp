class Solution {
public:
    
    
   
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> finalOrder;
        int rc, lc, tr, br;
        tr = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        br = n-1;
        rc = m - 1;
        lc = 0;
        
        while(tr <= br && lc <=rc ){
            for(int i = lc ; i <= rc; i++)
                finalOrder.push_back(matrix[tr][i]);
             tr++;
            for(int i = tr; i <= br; i++)
                finalOrder.push_back(matrix[i][rc]);
            rc--;
            if(br >= tr){
            for(int i = rc ; i >=lc ; i--)
                finalOrder.push_back(matrix[br][i]);
            br--;
            }
            if(rc >= lc){
            for(int i = br ; i >= tr ; i--)
                finalOrder.push_back(matrix[i][lc]);
            lc++;
            }
            
        }
     
        return finalOrder;
    }
};