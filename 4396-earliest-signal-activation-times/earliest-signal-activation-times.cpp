class Solution {
public:
    using T = tuple<long long, int, int>; // time, node, from

    vector<long long> earliestActivationTimes(
        int n,
        vector<vector<int>>& edges,
        vector<int>& requiredSignals
    ) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<long long> ans(n, -1);

        unordered_map<int, unordered_set<int>> mpp;

        priority_queue<T, vector<T>, greater<T>> pq;

        // Node 0 is initially activated
        ans[0] = 0;

        // Send signals from node 0
        for (auto [next, delay] : adj[0]) {
            pq.push({delay, next, 0});
        }

        while (!pq.empty()) {
            auto [time, node, from] = pq.top();
            pq.pop();

            if (ans[node] != -1)
                continue;

            // Count distinct incoming signal sources
            mpp[node].insert(from);

            if (mpp[node].size() < requiredSignals[node])
                continue;

            // Node activates when enough signals arrive
            ans[node] = time;

            // Activated node propagates signals
            for (auto [next, delay] : adj[node]) {
                if (ans[next] == -1) {
                    pq.push({time + delay, next, node});
                }
            }
        }

        return ans;
    }
};