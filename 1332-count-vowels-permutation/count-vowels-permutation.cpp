class Solution {
public:
    const long long M = 1e9 + 7;
    long long solve(int n, int len, vector<vector<int>>& dp, char c) {
        if (len >= n)
            return 1;

        if (dp[c - 'a'][len] != -1)
            return dp[c - 'a'][len] % M;

        long long count = 0;

        if (c == 'a') {
            count = (count + solve(n, len + 1, dp, 'e') % M) % M;
        }
        if (c == 'e') {
            count = (count + solve(n, len + 1, dp, 'a') % M) % M;
            count = (count + solve(n, len + 1, dp, 'i') % M) % M;
        }
        if (c == 'i') {
            count = (count + solve(n, len + 1, dp, 'a') % M) % M;
            count = (count + solve(n, len + 1, dp, 'e') % M) % M;
            count = (count + solve(n, len + 1, dp, 'o') % M) % M;
            count = (count + solve(n, len + 1, dp, 'u') % M) % M;
        }
        if (c == 'o') {

            count = (count + solve(n, len + 1, dp, 'i') % M) % M;
            count = (count + solve(n, len + 1, dp, 'u') % M) % M;
        }
        if (c == 'u') {

            count = (count + solve(n, len + 1, dp, 'a') % M) % M;
        }

        return dp[c - 'a'][len] = count % M;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(21, vector<int>(n + 1, -1));
        long long count = solve(n, 1, dp, 'a') + solve(n, 1, dp, 'e') +
                          solve(n, 1, dp, 'i') + solve(n, 1, dp, 'o') +
                          solve(n, 1, dp, 'u');

        return count % M;
    }
};