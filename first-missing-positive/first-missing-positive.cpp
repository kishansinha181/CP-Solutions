class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int firstNegative = nums.size();
      int j = 0;
      for(int i = 0 ; i < nums.size() ; ++i){
        if(nums[i] <= 0){
          continue;
        }
        if(nums[j] <= 0){
          swap(nums[i],nums[j]);
        }
        ++j;
      }
      for(int i = 0 ; i < nums.size() ; ++i){
        if(nums[i]<=0){
          firstNegative = i;
          break;
        }
      }
      
      for(int i = 0 ; i < firstNegative ; ++i){
          if(abs(nums[i]) - 1 < firstNegative)
            nums[abs(nums[i]) - 1] = -1 * abs(nums[abs(nums[i])-1]);
      }
      for(int i = 0 ; i < firstNegative; ++i){
        if(nums[i] > 0){
          return i+1;
        }
      }
      return firstNegative+1;
      
    }
};