class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, -1); // last occurence
        vector<int> upper(26, -1); // first Occurence;

        for (int i = 0; i < word.size(); i++) {
            if (islower(word[i])) {
                lower[word[i] - 'a'] = i;
            } else if (upper[word[i] - 'A'] == -1) {
                upper[word[i] - 'A'] = i;
            }
        }

        int count = 0;
        // cout << lower['e' - 'a'] << upper['E' - 'A'];
        for (int i = 0; i < 26; i++) {
            if (lower[i] == -1 || upper[i] == -1)
                continue;

            else if (lower[i] < upper[i])
                count++;
        }
        return count;
    }
};
