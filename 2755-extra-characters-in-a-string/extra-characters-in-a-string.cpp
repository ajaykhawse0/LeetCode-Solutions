class Solution {
public:
    int memo[51];

    int minExtraChar(string s, vector<string>& dictionary) {
        memset(memo, -1, sizeof(memo));
        return solve(0, s, dictionary);
    }

    int solve(int i, string &s, vector<string>& dict) {
        if(i >= s.size()) return 0;

        if(memo[i] != -1) return memo[i];

        // Consider current character as extra
        memo[i] = 1 + solve(i + 1, s, dict);

        for(const string &w : dict) {

            if(i + w.size() <= s.size() &&
               s.compare(i, w.size(), w) == 0) {

                memo[i] = min(memo[i],
                              solve(i + w.size(), s, dict));
            }
        }

        return memo[i];
    }
};