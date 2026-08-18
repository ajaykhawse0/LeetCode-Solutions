class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int n = s.length();
        int maxCount =  0;
        vector<int>freq(26,0);

        while(r<n){
            char c = s[r];
            freq[c-'A']++;
            maxCount=max(maxCount,freq[c-'A']);

            if(r-l+1-maxCount > k){
                freq[s[l]-'A']--;
                l++;
            }
            r++;
        }
        return n-l;
    }
};