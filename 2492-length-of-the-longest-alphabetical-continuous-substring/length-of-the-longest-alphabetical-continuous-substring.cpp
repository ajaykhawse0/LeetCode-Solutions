class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int maxLen = 1;
        int len = 1;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1] - 1) {
                len++;

            } else {
                maxLen = max(maxLen, len);
                len = 1;
            }
        }
            maxLen = max(maxLen,len);

        return maxLen;
    }
};