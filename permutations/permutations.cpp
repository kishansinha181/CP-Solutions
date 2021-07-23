class Solution {
public:
    vector<vector<int>> ans;
    
    void permute(vector<int> & arr, int i ){
        int n = arr.size();
        if(n-1 == i){
            ans.push_back(arr);
            return;
        }
        
        
            for(int j = i; j < n; j++){
                swap(arr[j], arr[i]);
                permute(arr,i+1);
                swap(arr[j],arr[i]);
            }
        
        
        
            
        
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // vector<vector<int>> ans;
        
        permute(nums,0);
        
        return ans;
        
        
    }
};