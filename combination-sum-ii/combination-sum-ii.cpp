class Solution {
public:
    
    void combSum(vector<int>&c, vector<vector<int> >& res, vector<int>& comb, int t, int k) {
        if(!t){
            res.push_back(comb);
            return;
        } else {
            for(int i=k;i<c.size();i++){
                
                if(c[i]<=t) {
                                        
                    comb.push_back(c[i]);
                    combSum(c, res, comb, t-c[i], i+1);
                    int curr = comb.back();
                    comb.pop_back();
                    while(i < c.size()-1 && c[i+1] == curr){
                        i++;
                    }
                }
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> comb;
        
        combSum(candidates, res, comb, target, 0);
        
        return res;
    }
};