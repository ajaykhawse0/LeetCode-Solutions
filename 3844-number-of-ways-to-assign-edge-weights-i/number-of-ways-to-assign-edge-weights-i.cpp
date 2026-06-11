class Solution {
public:
int findDepth(vector<vector<int>>&adj,int child,int par){
     int depth=0;

     for(auto&node:adj[child]){
        if(node==par)continue;
        depth = max(depth,1+findDepth(adj,node,child));
     }

     return depth;

}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int MOD = 1e9+7;
        vector<vector<int>>adj(edges.size()+2);
        
        for(auto&edge:edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int depth = findDepth(adj,1,-1);

        long long ans = 1;
        int  i = 1;
        while(i<depth){
            ans = (ans*2)%MOD;
            i++;
        }

        return ans%MOD;

    }
};