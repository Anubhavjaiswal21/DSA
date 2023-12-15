class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        stack<char>stck;
        bool flag = false;
        int i = 0;
        while(i < s.length()){
        if(!flag){
        i++;
        flag = true;
        continue;
        }
        if(s[i] == '('){
         res += s[i];
        stck.push(s[i]);
        }
        else if(!stck.empty()){
         res += s[i];
        stck.pop();
        }
        else if(stck.empty() == true && s[i] == ')'){
        flag = false;
        }
         i++;
        }
          return res;
    }
};