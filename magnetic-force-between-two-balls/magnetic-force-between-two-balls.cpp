class Solution {
public:
    bool isPossible(vector<int> position , int m, int min_sep){
        int last_magnet = position[0];
        int cnt =1;
        for(int i = 1; i <position.size(); i++){
            if(position[i]- last_magnet>=min_sep){
                cnt++;
                last_magnet = position[i];
                
                if(cnt == m)
                    return true;
                
            }
                        
        }
        return false;
        
        
        
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int s = 0;
        int ans = 0;
        int e = position[n-1] - position[0];
        while(s<=e){
            int mid = (s+e)/2;
            if(isPossible(position,m, mid )){
                ans = mid;
                s = mid+1;
    }
            else
                e = mid -1;
        }
        
        return ans;
    }
};