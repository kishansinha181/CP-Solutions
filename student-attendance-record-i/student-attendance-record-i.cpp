class Solution {
public:
    bool checkRecord(string s) {
        int absents = 0;
        for(auto c: s)
            if(c == 'A')
                absents++;
        if(absents>=2)
            return false;
        return s.find("LLL") == string::npos;
    }
};