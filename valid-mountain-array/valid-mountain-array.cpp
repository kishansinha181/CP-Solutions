class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3)
            return false;
        int i = 0;
        while(i < n-1){
            if(arr[i+1] > arr[i])
                i++;
            else
                break;
        }
        
        
        if(i == n-1 || i == 0)
            return false;
        while(i+1 <= n-1){
           if(arr[i+1] < arr[i])
               i++;
            else
                return false;
            
        }
        
        if(i == n-1)
            return true;
        return false;
       
    }
};