class Solution {
public:
    using ll = long long;
    ll fun(string text, string pat) {
        ll ans = 0;
        unordered_map<char, ll> mpp;

        for (char c : text) {
            if (c == pat[1]) {
                ans += mpp[pat[0]];
            }
            mpp[c]++;
        }
        return ans;
    }
    long long maximumSubsequenceCount(string text, string pattern) {

        return max(fun(pattern[0] + text, pattern),
                   fun(text + pattern[1], pattern));
    }
};