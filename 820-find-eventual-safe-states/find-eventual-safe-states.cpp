class Solution {
public:

    bool dfs(int node, vector<int>& vis, vector<vector<int>>& graph) {
        if (vis[node] == 1) return false; // cycle
        if (vis[node] == 2) return true;  // already safe

        vis[node] = 1;

        for (auto &nei : graph[node]) {
            if (!dfs(nei, vis, graph)) {
                return false;
            }
        }

        vis[node] = 2; 
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (dfs(i, vis, graph)) {
                ans.push_back(i);
            }
        }

        return ans; 
    }
};