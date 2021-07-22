  

class Solution {
public:
    

    vector<int> dailyTemperatures(vector<int>& T) {
       vector<int> res;
        stack<int> s;
        
        int n=T.size()-1;
        for(int i=n;i>=0;i--){
            if(s.empty()){
                res.push_back(0);
            }
            else if(!s.empty() and T[s.top()]>T[i]){
                res.push_back(s.top()-i);
            }
            else{
                while(!s.empty() and T[s.top()]<=T[i]){
                    s.pop();
                }
                if(s.empty()){
                    res.push_back(0);
                }
                else{
                    res.push_back(s.top()-i);
                }
            }
            s.push(i);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};