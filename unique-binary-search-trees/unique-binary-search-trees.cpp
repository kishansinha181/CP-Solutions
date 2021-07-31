class Solution {
public:
    int numTrees(int n) {
        //number of bsts is simply the nth catalan number

        //Catalan Number, Cn = C0Cn-1 + C1Cn-2 + C2Cn-3 + .. 
        
        //c[3] = C0C2 + C1C1 + C2C0
        
        int catalan[n+1];
        catalan[0] = 1;
        catalan[1] = 1;
        
        for(int i =2 ; i<=n; i++){
            int x = 0;
            for(int j = 0; j < i; j++)
                x+= catalan[j]*catalan[i-j - 1];
            catalan[i] = x;
        }
        
        return catalan[n];
    }
};