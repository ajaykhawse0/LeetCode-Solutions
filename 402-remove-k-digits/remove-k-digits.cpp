class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char>st;

        for(char c:s){
            while(k>0 && !st.empty() && st.top()>c){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        string ans ;

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        auto pos = ans.find_first_not_of("0");

        return (pos!=string::npos)?ans.substr(pos):"0";

    }
};