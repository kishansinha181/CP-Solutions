class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
	    int lis[n];
	    int lds[n];
	    lis[0] = 1;
	    lds[n-1] = 1;
	    for(int i = 1; i < n; i++){
	        lis[i] = 1;
	        for(int j = i-1; j>=0; j--){
	            if(nums[j] < nums[i])
	                lis[i] = max(lis[i], 1 + lis[j]);
	        }
	    }
	    
	    for(int i = n-2; i >=0; i--){
	        lds[i] = 1;
	        for(int j = i+ 1; j < n; j++){
	            if(nums[j] < nums[i])
	                lds[i] = max(lds[i], 1 + lds[j]);
	        }
	    }
	    
	    int ans = 0;
	    for(int i = 0; i < n; i++){
            if(lis[i]!=1 and lds[i]!=1)
	        ans = max(ans, lis[i] + lds[i] - 1);
	    }
	    
	    return n - ans ;
    }
};