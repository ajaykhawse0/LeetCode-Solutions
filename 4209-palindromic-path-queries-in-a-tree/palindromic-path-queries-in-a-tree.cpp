class Solution {
public:
    unordered_map<int, vector<int>> adj;

    vector<int> tin, tout, eulerTour;
    vector<int> segTree;

    vector<vector<int>> ancestorTable;
    vector<int> depth;

    int timer = 0;
    int n, cols;

    // DFS: Euler Tour + depth + immediate parent
    void dfs(int node, int par, string& s) {
        tin[node] = timer;

        eulerTour[timer] = (1 << (s[node] - 'a'));
        timer++;

        ancestorTable[node][0] = par;

        for (int child : adj[node]) {
            if (child == par)
                continue;

            depth[child] = depth[node] + 1;
            dfs(child, node, s);
        }

        tout[node] = timer;
        eulerTour[timer] = (1 << (s[node] - 'a'));
        timer++;
    }

    // Build Segment Tree
    void buildSegTree(int i, int l, int r) {
        if (l == r) {
            segTree[i] = eulerTour[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegTree(2 * i + 1, l, mid);
        buildSegTree(2 * i + 2, mid + 1, r);

        segTree[i] = segTree[2 * i + 1] ^ segTree[2 * i + 2];
    }

    // Point Update
    void updateSegTree(int pos, int val, int i, int l, int r) {
        if (l == r) {
            segTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid) {
            updateSegTree(pos, val, 2 * i + 1, l, mid);
        } else {
            updateSegTree(pos, val, 2 * i + 2, mid + 1, r);
        }

        segTree[i] = segTree[2 * i + 1] ^ segTree[2 * i + 2];
    }

    // Range XOR Query
    int querySearch(int start, int end, int i, int l, int r) {
        if (l > end || r < start)
            return 0;

        if (start <= l && r <= end)
            return segTree[i];

        int mid = l + (r - l) / 2;

        return querySearch(start, end, 2 * i + 1, l, mid) ^
               querySearch(start, end, 2 * i + 2, mid + 1, r);
    }

    // Build Binary Lifting Table
    void buildAncestorTable() {
        for (int j = 1; j < cols; j++) {
            for (int node = 0; node < n; node++) {
                int prev = ancestorTable[node][j - 1];

                if (prev != -1) {
                    ancestorTable[node][j] = ancestorTable[prev][j - 1];
                }
            }
        }
    }

    // Lowest Common Ancestor
    int getLCA(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < cols; j++) {
            if (diff & (1 << j)) {
                u = ancestorTable[u][j];
            }
        }

        if (u == v)
            return u;

        for (int j = cols - 1; j >= 0; j--) {
            if (ancestorTable[u][j] != ancestorTable[v][j]) {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,
                                vector<string>& queries) {
        this->n = n;

        // Reset state
        adj.clear();
        timer = 0;

        // Build graph
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Initialize arrays
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        eulerTour.assign(2 * n, 0);

        cols = 1;
        while ((1 << cols) <= n)
            cols++;

        ancestorTable.assign(n, vector<int>(cols, -1));

        // Step 1: DFS
        depth[0] = 0;
        dfs(0, -1, s);

        // Step 2: Build Segment Tree
        int N = 2 * n;
        segTree.assign(4 * N, 0);

        buildSegTree(0, 0, N - 1);

        // Step 3: Build Binary Lifting Table
        buildAncestorTable();

        // Step 4: Process Queries
        vector<bool> res;

        for (string& q : queries) {
            stringstream ss(q);
            string type;

            ss >> type;

            if (type == "update") {
                int node;
                char c;

                ss >> node >> c;

                int charVal = (1 << (c - 'a'));
                s[node] = c;

                // Update entry and exit positions
                eulerTour[tin[node]] = charVal;
                eulerTour[tout[node]] = charVal;

                updateSegTree(tin[node], charVal, 0, 0, N - 1);

                updateSegTree(tout[node], charVal, 0, 0, N - 1);
            } else {
                int u, v;
                ss >> u >> v;

                int lcaNode = getLCA(u, v);

                // Root-to-node masks
                int maskU = querySearch(0, tin[u], 0, 0, N - 1);

                int maskV = querySearch(0, tin[v], 0, 0, N - 1);

                int lcaMask = (1 << (s[lcaNode] - 'a'));

                // Path mask
                int mask = maskU ^ maskV ^ lcaMask;

                // At most one character has an odd frequency
                res.push_back((mask & (mask - 1)) == 0);
            }
        }

        return res;
    }
};