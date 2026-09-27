class Solution {
public:
    string reverseParentheses(string s) {
    int n = s.size();
     stack<int>st;
     queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
      if(s[i]=='('){
        st.push(i);
      }
      else if(s[i]==')'){
        q.push({st.top(),i});
        st.pop();
      }
      
    }

    while(!q.empty()){
        cout<<q.front().first<<" , "<<q.front().second<<endl;
        reverse(s.begin()+q.front().first,s.begin()+q.front().second);
        q.pop();

    }
    string ans;

    for(char c:s){
        if(c=='(' || c==')'){
            continue;
        }
        ans += c;
    }

    return ans;}
};