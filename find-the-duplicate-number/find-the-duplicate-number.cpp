class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int t = nums[0];
        int h = nums[0];
        while(true){
            t = nums[t];
            h = nums[nums[h]];
            if(t == h)
                break;
        }
        t = nums[0];
        while(t!=h){
            t = nums[t];
            h = nums[h];
        
        }
        return t;
    }
};