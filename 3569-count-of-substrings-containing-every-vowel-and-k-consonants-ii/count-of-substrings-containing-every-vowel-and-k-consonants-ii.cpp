class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    long long countOfSubstrings(string word, int k) {
        unordered_map<char, int> vowels;

        int n = word.size();

        // precompute the next consonants
        vector<int> nextCons(n);
        int lastCon = n;

        for (int i = n - 1; i >= 0; i--) {
            nextCons[i] = lastCon;

            if (!isVowel(word[i])) {
                lastCon = i;
            }
        }

        // sliding window
        long long res = 0;

        int l = 0;
        int r = 0;
        int cons = 0;
        while (r < n) {
            if (isVowel(word[r])) {
                vowels[word[r]]++;
            } else {
                cons++;
            }

            while (l < r && cons > k) {
                if (isVowel(word[l])) {
                    vowels[word[l]]--;

                    if (vowels[word[l]] == 0) {
                        vowels.erase(word[l]);
                    }
                } else {
                    cons--;
                }
                l++;
            }

            while (l < r && vowels.size()==5 && cons == k) {
                res += nextCons[r] - r;

                if (isVowel(word[l])) {
                    vowels[word[l]]--;

                    if (vowels[word[l]] == 0) {
                        vowels.erase(word[l]);
                    }
                } else {
                    cons--;
                }
                l++;
            }

            r++;
        }
    return res;}
};