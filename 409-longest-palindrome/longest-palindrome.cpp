class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>freq(58,0);
        bool odd = false;
        int len = 0;
        for(char c:s){
            freq[c-'A']++;
        }

        for(int i=0;i<58;i++){
            if(freq[i]&1){
                odd = true;
                len += freq[i]-1;
            }
            else{
                len += freq[i];
            }
        }

        if(odd){
            len++;
        }
        return len;
    }
};