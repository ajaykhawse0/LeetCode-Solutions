class Solution {
public:
    
    int dfs(int curr,int par,int dis,vector<vector<pair<int,int>>>&adj,int signalSpeed){
        int cnt =  (dis%signalSpeed==0)?1:0;
        
         for(auto[child,wt]:adj[curr]){
            if(child==par)continue;

            cnt += dfs(child,curr,dis+wt,adj,signalSpeed);
         }

         return cnt;
        
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int nodes = edges.size()+1;
        //dfs for every node will be used here
        vector<vector<pair<int,int>>>adj(nodes);

        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});

        }

        vector<int>ans(nodes);

        for(int curr = 0;curr<nodes;curr++){
            int validPairs = 0;
            int res = 0;
            for(auto[child,wt]:adj[curr]){
              int cnt =  dfs(child,curr,wt,adj,signalSpeed);
              res += validPairs*cnt;
              validPairs += cnt;
            }

            ans[curr]=(res);
        }
 return ans;   }
};