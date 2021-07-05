class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
         sort(points.begin(),points.end());
        vector <vector <int> >v;
        int count=0;
        for(auto i:points){
            if(v.empty()){
                v.push_back(i);
                count++;
            }
            else{
                if(i[0]<=v[0][1]){
                    v[0][1]=min(v[0][1],i[1]);
                }
                else{
                    v.pop_back();
                    v.push_back(i);
                    count++;
                }
            }
        }
        return count;
        
    }
};