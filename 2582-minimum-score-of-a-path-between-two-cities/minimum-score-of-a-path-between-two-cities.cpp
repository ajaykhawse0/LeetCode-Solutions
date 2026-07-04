class Solution {
public:typedef pair<int,int>P;
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<P>>adj(n+1);
        for(auto&road:roads){
            int u = road[0];
            int v = road[1];
            int cost = road[2];

            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }

        queue<int>q;
        q.push(1);
        int ans = INT_MAX;
        vector<int>vis(n+1,0);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto&[nei,cost]:adj[node]){
                    ans = min(ans,cost);
                if(!vis[nei]){
                    vis[nei]=1;
                    q.push(nei);
                }
            }
        }
  return ans;  }
};