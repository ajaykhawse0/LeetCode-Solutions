class Solution {
public:
    vector<vector<int>> listBuilder(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return adj;
    }

    int dfs(vector<vector<int>>& adj, int node, int parent, int edgesLeft) {
        if (edgesLeft < 0)
            return 0;
        int nodesTraversed = 1;

        for (auto& child : adj[node]) {
            if (child != parent) {
                nodesTraversed += dfs(adj, child, node, edgesLeft - 1);
            }
        }
        return nodesTraversed;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        auto adj1 = listBuilder(edges1);
        auto adj2 = listBuilder(edges2);

        int secondTreeNodes = 0;

        int m = adj2.size();

        for (int i = 0; i < m; i++) {
            // we can add k-1 edges only as in the question is given that one
            // edge will be connected from first(Another) tree
            secondTreeNodes = max(secondTreeNodes, dfs(adj2, i, -1, k - 1));
        }

        int n = adj1.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            res[i] = dfs(adj1, i, -1, k) + secondTreeNodes;
        }

        return res;
    }
};