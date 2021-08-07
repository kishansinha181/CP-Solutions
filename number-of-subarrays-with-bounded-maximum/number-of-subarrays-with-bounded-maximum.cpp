class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& arr, int L, int R) {
        int start = -1, end = -1;
        int ans = 0;
        for(int i = 0; i< arr.size(); i++){
            if( arr[i] >= L )
                end = i;
            if(arr[i] > R)
                start = i;
             if(arr[i] < L);
            ans += end - start ;
        }
        
        return ans;
    }
};