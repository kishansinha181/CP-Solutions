class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0 ;
        for(int i =0;i < nums.size(); i++)
            res = res ^ nums[i];
        
        //res is x ^ y ( where x and y are the two unique numbers)
        
        //Try to find the position of the first set bet in res
        
        int temp = res;
        int pos = 0;
        
        while((temp&1)!=1){
            pos++;
            temp = temp>>1;
        }
        
        int mask = 1<<pos;
        
        //find xor of all numbers which has set bit at the pos position
        
        int x = 0;
        for(int i =0 ; i< nums.size(); i++){
            if(nums[i]&mask)
                x^=nums[i];
                
        }
        
        int y = res^x;
        
        return {x,y};
           
        
    }
};