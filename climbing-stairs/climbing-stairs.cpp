#define ll long long
#include<map>
class Solution {
public:
    const long mod = 1000000007;
    ll x,y;
   void fib(ll n, ll&x, ll&y){
    if(n==0){
        x = 0;
        y = 1;
        return ;
    }
     
    if(n&1){
        fib(n-1, y, x);
        y=(y+x);
    }else{
        ll a, b;
        fib(n>>1, a, b);
        y = (a*a+b*b);
        x = (a*b + a*(b-a));
    }
}
    
    
    int climbStairs(int n) {
         fib(n+1,x,y);
        return x;
    }
};