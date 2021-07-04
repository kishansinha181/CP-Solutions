class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       
        if(strs.size()==0)  return "";
        
         string prefix="";
        
        for(int z=0; z<strs[0].size();z++){
            int i=1;
            for(; i<strs.size() && strs[i].size()>z; i++){
                if(strs[i][z]!=strs[0][z])
                    return prefix;
            }
            if(i==strs.size()) prefix+=strs[0][z];
        }
        return prefix;
        
    }
};