class Solution {
public:
    bool isPalindrome(string s) {
        int n= s.length();

    int low=0,high= n-1;

    while(low<high){

        if (!isalnum(s[low])){
            low++;
        }

        else if(!isalnum(s[high])){
            high--;
        }

        else if(tolower(s[low])!=tolower(s[high])){
            return false;
        }else{
            low++;
            high--;
        }



    }
    return true;

    }
};