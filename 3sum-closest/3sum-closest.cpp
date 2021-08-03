class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int delta=INT_MAX, ans;
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(target-sum)<delta){
                    ans=sum;
                    delta=abs(target-sum);
                }
                if(sum<target) j++;
                else if(sum>target) k--;
                else return target;
            }
        }
        return ans;
    }
};