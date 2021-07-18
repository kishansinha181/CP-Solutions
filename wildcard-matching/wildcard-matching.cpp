class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(p.size() + 1, vector<int>(s.size() + 1));
	memo[0][0] = 1;
	for(int i = 1; i <= p.size(); i++)
		memo[i][0] = p[i - 1] == '*' && memo[i - 1][0];

	for(int i = 1; i <= p.size(); i++) {
		for(int j = 1; j <= s.size(); j++) {
			if(p[i - 1] == '*')
				memo[i][j] = memo[i - 1][j] || memo[i][j - 1];
			else if(p[i - 1] == '?' || p[i - 1] == s[j - 1])
				memo[i][j] = memo[i - 1][j - 1];
		}
	}

	return memo.back().back();
    }
};