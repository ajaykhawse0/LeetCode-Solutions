
class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> freq(26, 0);

        // Count only existing letters
        for (char c : s) {
            if (c != '?') {
                freq[c - 'a']++;
            }
        }

        string chosen;

        // Select the optimal replacement letters
        for (char c : s) {
            if (c == '?') {
                int mn = 0;

                for (int i = 1; i < 26; i++) {
                    if (freq[i] < freq[mn]) {
                        mn = i;
                    }
                }

                chosen += char('a' + mn);
                freq[mn]++;
            }
        }

        // Lexicographically smallest assignment
        sort(chosen.begin(), chosen.end());

        int j = 0;
        for (char &c : s) {
            if (c == '?') {
                c = chosen[j++];
            }
        }

        return s;
    }
};
