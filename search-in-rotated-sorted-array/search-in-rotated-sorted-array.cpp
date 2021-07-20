class Solution {
public:
    // int pivotIdx(vector<int> arr){
    //     int lo = 0;
    //     int hi = arr.size()-1;
    //     int ans = 0;
    //     while(lo<=hi){
    //         int mid = lo + (hi - lo)/2;
    //         if(mid + 1 <= hi && arr[mid] > arr[mid+1]){
    //             ans = mid;
    //             hi = mid - 1;
    //         }
    //         else lo = mid + 1;
    //     }
    //     return ans;
    // }
    int search(vector<int>& nums, int target) {
       int lo = 0;
        int hi = nums.size() - 1;
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[lo] <= nums[mid] ){
                if(target <= nums[mid] && target >= nums[lo])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            else if(nums[hi] > nums[mid]){
                if(target >= nums[mid] && target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
                
            }
            
            
        }
        return -1;
        
    }
};