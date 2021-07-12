class Solution {
public:
    vector<int> diStringMatch(string s) {
         int ci=0; 
        int cd=s.length();
        vector<int> v;
        for(char c:s)
        v.push_back(c=='I'?ci++:cd--);
        v.push_back(cd);   
        return v;
    }
};