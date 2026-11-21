class Solution {
public:
    char dfs(vector<bool>&vis,char c,unordered_map<char,vector<char>>&graph){
        if(vis[c-'a'])return c;
        vis[c-'a'] = true;
      
        char minCh = c;

        for(char ch : graph[c]){
            if(!vis[ch-'a'])
            minCh = min(minCh,dfs(vis,ch,graph));
        }

        return minCh;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        //make a an graph for easy traversal;

        unordered_map<char,vector<char>>graph;

        for(int i=0;i<s1.length();i++){
            graph[s1[i]].push_back(s2[i]);
            graph[s2[i]].push_back(s1[i]);
        }

        string result;

        for(char c:baseStr){
            vector<bool>vis(26,false);

            char minCh = dfs(vis,c,graph);

            result += minCh;
        }
    return result;}
};