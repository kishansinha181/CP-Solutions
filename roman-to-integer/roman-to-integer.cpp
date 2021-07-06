class Solution {
public:
   void fillHashTable(unordered_map<char, int> &val)
    {
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
    }
    
    int romanToInt(string s) 
    {
        unordered_map<char, int> val;
        fillHashTable(val);
        int result = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && val[s[i + 1]] > val[s[i]]) {
                result += val[s[i + 1]] - val[s[i]];
                i += 1;
            }
            else {
                result += val[s[i]];
            }
        }
        return result;
    }
};