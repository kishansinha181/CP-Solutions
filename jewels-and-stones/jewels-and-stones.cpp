class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> m;
        for(auto x: stones)
            m[x]++;
        int count = 0;
        for(auto x: jewels)
            count += m[x];
        return count;
    }
};