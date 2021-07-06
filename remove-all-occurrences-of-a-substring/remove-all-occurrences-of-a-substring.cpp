class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true){
            auto idx = s.find(part);
            if(idx== string::npos) return s;
            
            s = s.substr(0,idx) + s.substr(idx+part.size());
        }
        return s;
        
    }
};