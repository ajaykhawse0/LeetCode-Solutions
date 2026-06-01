class Solution {
public:int count=0,n;
    int countSubstrings(string s) {
        n = s.length();

        for(int i=0;i<n;i++){
            extendedPalindrome(s,i,i);
            extendedPalindrome(s,i,i+1);
        }
    return count;}

    void extendedPalindrome(string s,int l,int r){
        while(l>=0 && r<n){
            if(s[l]!=s[r])return ;
            count++;
            l--;
            r++;
        }
    }
};