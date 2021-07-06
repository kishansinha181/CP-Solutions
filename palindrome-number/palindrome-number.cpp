class Solution {
public:
    bool isPalindrome(int x) {
         int y = x;
        long num = 0;
        int remainder;
        if(x < 0) {
            return false;
        }
        else {
            while(y!=0) {
                remainder = y%10;
                num = num*10 + remainder;
                y /= 10;
            }
            return num == x ? true : false;
        }
    }
};