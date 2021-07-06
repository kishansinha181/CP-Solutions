class Solution {
public:
    string LESS_THEN_20[20] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    
    string TENS[10] = {"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    
    string THOUSANDS[4] = {""," Thousand"," Million"," Billion"};
    
     string GetSpace(string res){
        return res.empty() ? "" : " ";
    }
    
    string process_last_three(int num){
        if(num==0) return "";
        if(num<20) return LESS_THEN_20[num];
        else if(num<100){
            string s = process_last_three(num%10);
            return TENS[num/10] + GetSpace(s) + s;
        }
        else{
            string s = process_last_three(num%100);
            return LESS_THEN_20[num/100] +" Hundred"+ GetSpace(s) + s;
        }
    }
    string numberToWords(int num) {
        if(num==0) return "Zero";
        int i=0;   
        string res;
        while(num){
            if(num%1000){
                res = process_last_three(num % 1000) + THOUSANDS[i] + GetSpace(res) + res;
            }
            num /= 1000;
            i++;
        }
        return res;
    }
};