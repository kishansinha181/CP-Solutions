class Solution {
public:
    
    vector<int> nearestSmallerRight(vector<int>& heights){
        int n= heights.size();
        stack<int>s;
        vector<int>ans(n);
        for(int i =n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();
            
            if(s.empty()) ans[i] = n;
            else ans[i]= s.top();
            
            s.push(i);
        }
        return ans;
    }
    
    vector<int> nearestSmallerLeft(vector<int>& heights){
        int n= heights.size();
        stack<int>s;
        vector<int>ans(n);
        for(int i =0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();
            
            if(s.empty()) ans[i] = -1;
            else ans[i]= s.top();
            
            s.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int>nsl,nsr;

        nsl = nearestSmallerLeft(heights);
        nsr = nearestSmallerRight(heights);
       int maxx =INT_MIN;
        for(int i=0;i<n;i++){
            maxx = max(maxx,(nsr[i]-nsl[i]-1)*heights[i]);
        }
       return maxx; 
    }
};