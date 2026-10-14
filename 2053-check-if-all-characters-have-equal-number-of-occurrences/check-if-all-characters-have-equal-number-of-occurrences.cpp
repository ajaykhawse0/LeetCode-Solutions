class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int>freq(26,0);

        for(char c:s){
            freq[c-'a']++;
        }
        int val = freq[s[0]-'a'];

        for(char c:s){
            if(freq[c-'a']!=val)return false;
        }
    return true;}
};