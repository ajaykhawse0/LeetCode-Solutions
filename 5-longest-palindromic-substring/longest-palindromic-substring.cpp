class Solution {
public:
    int start = 0, maxLen = 1;
    string s;
    void expandAroundCenter(int l, int r,int n) {
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
        this->s = s;
        int n = s.size();
        for (int i = 0; i <n ; i++) {
            // even length
            expandAroundCenter(i, i,n);
            // odd length
            expandAroundCenter(i, i + 1,n);
        }
        return s.substr(start, maxLen);
    }
};