class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         int n=nums.size();
        if(n<4) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                for(int j=i+1;j<n-2;j++){
                    if(j==i+1 || nums[j]!=nums[j-1]){
                        int lo=j+1,hi=n-1;
                        while(lo<hi){
                            int sum=nums[i]+nums[j]+nums[lo]+nums[hi];
                            if(sum==target){
                                ans.push_back({nums[i],nums[j],nums[lo],nums[hi]});
                                while(lo<hi && nums[lo]==nums[lo+1]) lo++;
                                while(lo<hi && nums[hi]==nums[hi-1]) hi--;
                                lo++;hi--;
                            }else if(sum<target) lo++;
                            else hi--;
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};