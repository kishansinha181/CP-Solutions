class Solution {
public:
    int left[30005];
    int right[30005];
    int trap(vector<int>& arr) {
        if(arr.size()==0)
            return 0;
        left[0] = arr[0];
        for(int i =1; i < arr.size(); i++){
            left[i] = max(left[i-1], arr[i-1]);
        }
        right[arr.size() - 1] = 0;
        for(int i = arr.size()-2; i >=0; i--)
            right[i] = max(right[i+1], arr[i+1]);
        
        int ans = 0;
        for(int i = 0; i < arr.size(); i++){
            int op1 = left[i];
            int op2 = right[i];
            int x = min(op1, op2) - arr[i];
            ans += (x<=0 ? 0 : x); 
        }
        return ans;
    }
    
};