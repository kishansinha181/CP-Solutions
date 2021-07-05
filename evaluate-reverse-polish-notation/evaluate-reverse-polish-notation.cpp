#include <string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
    
        
       for(int i = 0; i < tokens.size(); i++){
           if (tokens[i] != "+" && tokens[i] != "/"  && tokens[i] != "*"  && tokens[i] != "-")
        {
            int num = stoi(tokens[i]);
            s.push(num);
        }
           else if(tokens[i] == "+"){
               int x = (s.top());
               s.pop();
               int y = (s.top());
               s.pop();
               s.push(x+y);
           }
           else if(tokens[i] == "-"){
               int x = (s.top());
               s.pop();
               int y = (s.top());
               s.pop();
               s.push(y-x);
           }
          else if(tokens[i] == "/"){
               int x =(s.top());
               s.pop();
               int y = (s.top());
               s.pop();
               s.push(y/x);
           }
           else if(tokens[i] == "*"){
               int x = (s.top());
               s.pop();
               int y = (s.top());
               s.pop();
               s.push(x*y);
           }
           
       }
        
        return s.top();
    }
};