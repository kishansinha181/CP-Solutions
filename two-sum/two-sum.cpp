#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a,b;
        unordered_map<int,int> hash;
        for(int i = 0 ; i < nums.size(); i++){
            hash[nums[i]] = i;
        }
        
       for(int i = 0 ; i < nums.size(); i++){
           if(hash.find(target - nums[i])!= hash.end()){
               if(i == hash[target - nums[i]]);
               else 
                 return {i,hash[target - nums[i]]};
           }
       }
        
       return {1,2};
       
    }
};