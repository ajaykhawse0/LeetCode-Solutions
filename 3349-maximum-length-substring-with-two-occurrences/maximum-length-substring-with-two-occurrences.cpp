class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int i=0;
        int j=0;
        int maxLen = 0;
        vector<int>freq(26,0);
        while(j<n){
            freq[s[j]-'a']++;
            while(freq[s[j]-'a']>2){
                freq[s[i]-'a']--;
                i++;
            }
            maxLen = max(maxLen,j-i+1);
            j++;
        }
 return maxLen;   }
};