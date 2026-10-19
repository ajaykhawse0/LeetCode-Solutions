class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int>freq(26,0);

        for(char c:s){
            freq[c-'a']++;
        }
        
        for(int i=0;i<s.size();i++){
            if(freq[s[i]-'a']<k){
                int firstHalf = longestSubstring(s.substr(0,i),k);
                int secondHalf = longestSubstring(s.substr(i+1),k);

                return max(firstHalf,secondHalf);
            }
        }
    return s.size();}
};