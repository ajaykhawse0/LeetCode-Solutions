class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<bool>&vis,int&cnt,int curr){
        vis[curr]=true;
        cnt++;
        for(auto&v:adj[curr]){
            if(!vis[v]){
                dfs(adj,vis,cnt,v);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto&edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool>vis(n,false);
        int ans = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                int cnt = 0;
                bool isComplete = true;
                dfs(adj,vis,cnt,i);
                if(adj[i].size()!=cnt-1)continue;
                for(auto&u:adj[i]){
                    if(adj[u].size()!=cnt-1){
                        isComplete = false;
                        break;
                    }
                }
               if(isComplete) ans++;
            }
        }
 return ans;   }
};