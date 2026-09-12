class Solution {
public:
    int n;
    vector<int> nextIdx;

    struct Node {
        long long score = 0;
        array<int, 4> idx = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
        int cnt = 0;
    };

    vector<vector<Node>> memo;
    vector<vector<bool>> vis;

    int findNext(vector<vector<int>>& intervals, int end) {
        int l = 0, r = n - 1;
        int ans = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (intervals[mid][0] > end) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    bool smaller(const Node& a, const Node& b) {
        for (int i = 0; i < 4; i++) {
            if (a.idx[i] != b.idx[i])
                return a.idx[i] < b.idx[i];
        }
        return false;
    }

    Node solve(vector<vector<int>>& intervals, int i, int k) {

        if (i >= n || k == 0)
            return Node();

        if (vis[i][k])
            return memo[i][k];

        vis[i][k] = true;

        // Don't take current interval
        Node skip = solve(intervals, i + 1, k);

        // Take current interval
        int j = nextIdx[i];

        Node temp = solve(intervals, j, k - 1);

        Node take;
        take.score = temp.score + intervals[i][2];

        // Insert original index while maintaining sorted order
        int x = intervals[i][3];

        int p = 0;

        while (p < temp.cnt && temp.idx[p] < x) {
            take.idx[p] = temp.idx[p];
            p++;
        }

        take.idx[p] = x;

        for (int q = p; q < temp.cnt; q++) {
            take.idx[q + 1] = temp.idx[q];
        }

        take.cnt = temp.cnt + 1;

        // Choose better answer
        if (take.score > skip.score) {
            return memo[i][k] = take;
        }

        if (take.score < skip.score) {
            return memo[i][k] = skip;
        }

        // Equal score -> lexicographically smaller indices
        if (smaller(take, skip)) {
            return memo[i][k] = take;
        }

        return memo[i][k] = skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        nextIdx.resize(n);

        for (int i = 0; i < n; i++) {
            nextIdx[i] = findNext(intervals, intervals[i][1]);
        }

        int K = 4;

        memo.assign(n + 1, vector<Node>(K + 1));
        vis.assign(n + 1, vector<bool>(K + 1, false));

        Node ans = solve(intervals, 0, K);

        vector<int> result;

        for (int i = 0; i < ans.cnt; i++)
            result.push_back(ans.idx[i]);

        return result;
    }
};