class Solution {
public:
    vector<int> grayCode(int n) {
        int limit =pow(2, n);
            vector<int> ans;

            ans.push_back(0);

            // i xor i >> 1 will give you the gray code for i.
            for (int i = 1; i < limit; i++) {
                ans.push_back(i ^ (i >> 1));
            }

            return ans;
    }
};