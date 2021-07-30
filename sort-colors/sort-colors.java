class Solution {
    
    
    public void sortColors(int[] nums) {
        int lo = 0;
        int mid = 0;
        int hi = nums.length - 1;
        if(hi == 0)
            return;
        while(mid<=hi){
            if(nums[mid] == 0){
               
                
                int t = nums[mid];
                nums[mid] = nums[lo];
                nums[lo] = t;
                
                lo++;mid++;
                
            }
            
            else if(nums[mid] == 2){
                int t = nums[mid];
                nums[mid ] = nums[hi];
                nums[hi] = t;
                hi--;
            }
            else
                mid++;
        }
        
        return;
        
    }
}