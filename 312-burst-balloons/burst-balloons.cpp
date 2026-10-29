class Solution {
public:
    vector<vector<int>> memo;

    int solve(int i, int j, vector<int>& vec) {
        if (i > j) return 0;

        if (memo[i][j] != -1)
            return memo[i][j];

        int ans = 0;

        for (int k = i; k <= j; k++) {
            int coins = vec[i - 1] * vec[k] * vec[j + 1];

            coins += solve(i, k - 1, vec);
            coins += solve(k + 1, j, vec);

            ans = max(ans, coins);
        }

        return memo[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> vec = {1};

        for (int x : nums)
            vec.push_back(x);

        vec.push_back(1);

        int n = vec.size();

        memo.assign(n, vector<int>(n, -1));

        return solve(1, n - 2, vec);
    }
};