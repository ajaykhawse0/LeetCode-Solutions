class Solution {
public:
    string removeOuterParentheses(string s) {
        string str;
        int p = 0;
        for(char c:s){
           if(c=='('){
            if(p>0){
                str.push_back(c);
            }
            p++;
           }
           else{
            p--;
            if(p>0){
                str.push_back(c);
            }
           }
        }
    return str;}
};