class Solution {
public:
    int m;
    bool check(vector<vector<pair<int, int>>>& adj, int mxWt, int k) {
        vector<vector<int>> adj1(m);

        for (int i = 0; i < m; i++) {
            for (auto it : adj[i]) {
                auto [node, wt] = it;
                if (wt <= mxWt) {
                    adj1[i].push_back(node);
                }
            }
        }

        int comps = 0;
        vector<bool>visited(m,false);
        for(int i=0;i<m;i++){
           if(!visited[i]){
            comps++;
            if(comps>k)return false;
            dfs(adj1,i,visited);
           }
        }
    return true;}

    void dfs(vector<vector<int>>&adj,int node,vector<bool>&vis){
        vis[node] = true;

        for(auto child:adj[node]){
            if(!vis[child]){
                dfs(adj,child,vis);
            }
        }
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        m = n;
        vector<vector<pair<int, int>>> adj(n);
        int low = 0, high = -1e9, mid = 0;
        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});

            high = max(high, edge[2]);
        }

        // binary search
        int ans = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;

            if (check(adj, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};