class Solution {
public:
    int maxDistToClosest(vector<int>& arr) {
        int n = arr.size();
        int left[n];
        int right[n];
        left[0] = arr[0] == 1 ? 0: -20000;
        right[n-1] = arr[n-1] == 1? n-1: 20000;
        for(int i = 1; i < n; i++){
            if(arr[i] == 1)
                left[i] = i;
            else
                left[i] = left[i-1];
        }
        
        for(int i = n-2; i >= 0; i--){
            if(arr[i] == 1)
                right[i] = i;
            else
                right[i] = right[i+1];
        }
        
        int best = INT_MIN;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
               
                best = max(best,  min(right[i] - i, i - left[i]) );
            }
        }
       // for(int i = 0; i < n; i++)
       //     cout<<left[i]<<" ";
       //  cout<<endl;
       //   for(int i = 0; i < n; i++)
       //     cout<<right[i]<<" ";
       //  cout<<endl;
        return best;
    }
};