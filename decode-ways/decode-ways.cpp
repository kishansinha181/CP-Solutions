class Solution {
public:
    
    int numDecodings(string s) {
       if(s[0]=='0')
            return 0;
        int f0=1, f1=1, f2;
        for(int i=1; i<s.size(); i++) {
            f2 = int(s[i]!='0')*f1 + int(s[i-1]=='1'||s[i-1]=='2'&&s[i]<'7')*f0;
            f0 = f1;
            f1 = f2;
        }
        return f1;
    }
};