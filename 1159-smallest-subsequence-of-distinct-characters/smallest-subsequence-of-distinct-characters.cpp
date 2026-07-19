class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>last_occur(26);
        int n = s.size();
        for(int i=0;i<n;i++){
            last_occur[s[i]-'a']=i;
        }
        string ans = "";
        vector<bool>vis(26,false);

        for(int i=0;i<n;i++){
            if(vis[s[i]-'a'])continue;
            char ch = s[i];
            while(!ans.empty() && ans.back() > ch && last_occur[ans.back()-'a'] > i){
                vis[ans.back()-'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            vis[ch-'a'] = true;
        }
  return ans;  }
};