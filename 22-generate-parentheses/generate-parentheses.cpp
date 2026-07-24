class Solution {
public:
    void dfs(int open,int close,int n,vector<string>&ans,string temp){
           if(open==close && open+close == 2*n){
            ans.push_back(temp);
            return;

           }

           if(open<n){
            dfs(open+1,close,n,ans,temp + '(');
           }
           if(close<open){
            dfs(open,close+1,n,ans,temp + ')');
           }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        dfs(0,0,n,ans,"");
        return ans;
    }
};