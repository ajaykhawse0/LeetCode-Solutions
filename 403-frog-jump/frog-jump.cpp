class Solution {
public:
    unordered_map<long long, bool> memo;
    bool solve(int curr, int jump, int target, unordered_set<int>& stones) {
        if (curr == target)
            return true;
        if (jump <= 0)
            return false;
        if (!stones.count(curr))
            return false;

        long long key = ((long long)curr << 32) | jump;
        if (memo.count(key))
            return memo[key];

        bool ans = false;
        ans = solve(curr + jump - 1, jump - 1, target, stones);

        if (!ans)
            ans = solve(curr + jump, jump, target, stones);
        if (!ans)
            ans = solve(curr + jump + 1, jump + 1, target, stones);

        return memo[key] = ans;
    }
    bool canCross(vector<int>& stones) {
        if (stones[0] != 0 || stones[1] != 1)
            return false;

        memo.clear();

        unordered_set<int> st;

        for (int x : stones)
            st.insert(x);

        return solve(1, 1, stones[stones.size() - 1], st);
    }
};