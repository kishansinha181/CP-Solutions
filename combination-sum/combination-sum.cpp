class Solution {
public:
   vector<vector<int>>res;
    void sum(vector<int>&candidates,vector<int>&v,int n,int idx,int target)
    {
        if(target==0)
        {
            res.push_back(v);
            return ;
        }
        if(target<0)
        {
            return ;
        }
        for(int i=idx;i<n;i++)
        {
            v.push_back(candidates[i]);
            sum(candidates,v,n,i,target-candidates[i]);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>v;
        sum(candidates,v,n,0,target);
        return res;
    }
};