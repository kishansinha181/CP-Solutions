class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(256,-1);
        int i=0,start=-1,res=0;
        while(i<s.length())
        {
            if(pos[s[i]]>start)
                start=pos[s[i]];
            pos[s[i]]=i;
            res=max(res,i-start);
            i++;
        }
        return res;
    }
};