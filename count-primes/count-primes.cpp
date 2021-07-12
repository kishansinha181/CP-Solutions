class Solution {
public:
    int countPrimes(int n) {
         uint total = 0;
        if (n<=0)
            return 0;
        bool isprime[n+1];
        memset(isprime,true,sizeof(isprime));
        for(uint i{2} ; i*i < n ; ++i) {
            if (isprime[i]) {
                for(uint u=i<<1;u<n;u+=i)
                    isprime[u] = false;                             
            }      
        }
        for(uint i{2};i<n;++i) {
             if (isprime[i])
                ++total;
        }
        return total;
    }
};