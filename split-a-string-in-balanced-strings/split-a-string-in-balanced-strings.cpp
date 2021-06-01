class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.length();
	
	vector<int> l(n);
	vector<int> r(n);

	if (s[0] == 'L')
		l[0] = 1;
	else l[0] = 0;
	for (int i = 1; i < n ; i++) {
		if (s[i] == 'L')
			l[i] = l[i - 1] + 1;
		else
			l[i] = l[i - 1];
	}
	


	if (s[0] == 'R')
		r[0] = 1;
	else r[0] = 0;
	for (int i = 1 ; i < n; i++ ) {
		if (s[i] == 'R')
			r[i] = r[i - 1] + 1;
		else
			r[i] = r[i - 1];
	}


	int count = 0;

	for (int i = 0; i < n; i++) {
		if (l[i] == r[i])
			count++;
	}

	return count;
        
    }
};