class Solution {
public:
    string resultingString(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            
            if(st.empty()){
                st.push(s[i]);
            }
            else{
            //special case
            if(s[i]=='a' && st.top()=='z' || s[i]=='z' && st.top()=='a'){
                st.pop();
            }
            else if(abs(s[i]-st.top())==1){
                st.pop();
            }
            else{
                st.push(s[i]);
            }}
        }
    string ans="";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;

    }
};