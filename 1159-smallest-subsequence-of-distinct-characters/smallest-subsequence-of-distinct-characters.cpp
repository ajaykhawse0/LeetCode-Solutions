class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int>last_occur;
        int n = s.size();
        for(int i=0;i<n;i++){
            last_occur[s[i]]=i;
        }
        string ans = "";
        vector<bool>vis(26,false);

        for(int i=0;i<n;i++){
            if(vis[s[i]-'a'])continue;
            char ch = s[i];
            while(!ans.empty() && ans.back() > ch && last_occur[ans.back()] > i){
                vis[ans.back()-'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            vis[ch-'a'] = true;
        }
  return ans;  }
};