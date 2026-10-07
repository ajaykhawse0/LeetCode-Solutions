class Solution {
public://REC + BACK
    int maxLen = 0;
    unordered_set<string>st;
    int n;
    

    void solve(int i,int count,string&curr,string&s ){
        if(count<0)return;
        if(i==n){
            if(count==0){
                 if(curr.length()>maxLen){                  
                 maxLen = max(maxLen,(int)curr.length());
                st.clear();
            }
            if(maxLen==curr.length()){
                st.insert(curr);
            }
            }
            return;
            
        }

        if(s[i]!='(' && s[i]!=')'){
            curr.push_back(s[i]);//take
            solve(i+1,count,curr,s);
            curr.pop_back();//backtrack
            solve(i+1,count,curr,s);
            return;
        }

        curr.push_back(s[i]);
        solve(i+1,count+(s[i]=='('?1:-1),curr,s);
        curr.pop_back();//backtrack
        solve(i+1,count,curr,s);

    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        string curr;
        solve(0,0,curr,s);

        vector<string>res;

         for(auto&str:st){
            res.push_back(str);
         }
         return res;
    }
};