class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(char c:s){
            if(c!=']'){
                st.push(c);
            }
            else{
                string curr="";
                 while(st.top()!='['){
                     curr = st.top() + curr;
                     st.pop();
                 }
                 st.pop();//popping '['
                 string number="";

                 while(!st.empty() && isdigit(st.top())){
                    number = st.top() + number;
                    st.pop();
                 }

                 int times = stoi(number);

                 while(times--){
                    for(char ch : curr){
                        st.push(ch);
                    }
                 }

                
            }
        }

        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
    return ans;}
};