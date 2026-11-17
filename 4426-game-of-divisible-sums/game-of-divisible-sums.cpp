
class Solution {
    using ll = long long;

public:
    vector<vector<ll>> memo;
    int n;

    ll solve(int idx, int turn, vector<int>& nums) {
        if (idx == n) return 0;

        if (memo[idx][turn] != LLONG_MIN)
            return memo[idx][turn];

        ll op1 = nums[idx];

        int nextTurn1 = (nums[idx] % 3 == 0)
                            ? 1 - turn
                            : turn;

        if (turn == 1) op1 = -op1;

        op1 += solve(idx + 1, nextTurn1, nums);

        ll op2 = op1; // initialize with valid option 1

        if (idx + 1 < n) {
            ll sum = nums[idx] + nums[idx + 1];

            int nextTurn2 = (sum % 3 == 0)
                                ? 1 - turn
                                : turn;

            if (turn == 1) sum = -sum;

            op2 = sum + solve(idx + 2, nextTurn2, nums);
        }

        if (turn == 0)
            return memo[idx][turn] = max(op1, op2);

        return memo[idx][turn] = min(op1, op2);
    }

    long long maxDifference(vector<int>& nums) {
        n = nums.size();

        memo.assign(n, vector<ll>(2, LLONG_MIN));

        return solve(0, 0, nums);
    }
};
