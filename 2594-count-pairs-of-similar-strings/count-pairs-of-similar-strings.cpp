class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            vector<bool> isThere1(26, false);

            for (char c : words[i]) {
                isThere1[c - 'a'] = true;
            }

            for (int j = i + 1; j < n; j++) {
                vector<bool> isThere2(26, false);

                for (char c : words[j]) {
                    isThere2[c - 'a'] = true;
                }

                if (isThere1 == isThere2) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};