class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mpp;
        for(char c:s){
            mpp[c]++;
        }
        int evenLength=0;
        int odd = 0;
        for(auto&[c,freq]:mpp){
            if(freq%2==0){
                evenLength += freq;
            }
            else{
                evenLength += (freq-1);
                odd = 1;
            }
        }
        if(odd==1){
            evenLength+=1;
        }

    return evenLength;}
};