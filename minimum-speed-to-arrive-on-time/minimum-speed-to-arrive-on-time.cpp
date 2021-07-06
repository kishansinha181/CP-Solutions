class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int i=1,j=1000000000,ans=INT_MAX;
        
        while(i<=j)
        {
            int mid=(i+j)/2,k=0;
            double s=0;
            
            for(k=0;k<dist.size()-1;k++)
            {
                s=s+ceil(dist[k]/(mid+0.00));
            }
            
            s=s+(dist[k]/(mid+0.00));
            cout<<mid<<" "<<s<<endl;
            
            if(s<=hour)
            {
                ans=min(ans,mid);
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
        
        if(ans==INT_MAX)
            ans=-1;
        return ans;
    }
};