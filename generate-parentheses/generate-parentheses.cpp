class Solution {
public:
    bool check(string comb){
        int val = 0;
        for(int i=0;i<comb.length();i++){
            if(comb[i]=='('){
                val++;
            }
            else{
                val--;
            }
            if(val<0){
                return false;
            }
        }
        return comb[0]=='(' && val==0;
    } 
    
     vector<string> generateParenthesis(int n) {
        n *=2;
        vector<string> ans;
        for(int i=0;i<(1<<n);i++){
            string comb;
            for(int j=0;j<n;j++){
                int b = (i>>j)&1;
                if(b){
                    comb.push_back('(');
                }
                else{
                    comb.push_back(')');
                }
            }
            if(check(comb)){
                ans.push_back(comb);
            }
        }
        return ans;
    } 
};