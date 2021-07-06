class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
         map<int ,int> freq1,freq2;
        
        for(int i=0;i<nums1.size();i++)
            freq1[nums1[i]]++;
        
          for(int i=0;i<nums2.size();i++)
            freq2[nums2[i]]++;
        
        
        
        
         vector<int> ans;
        for(auto i=freq1.begin();i!=freq1.end();i++){
            int a=i->second;
            
            int b=freq2[i->first];
            int c=min(a,b);
            while(c--) ans.push_back(i->first);
            
        }
        return ans;
    }
};