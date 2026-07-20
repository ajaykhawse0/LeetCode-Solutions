class Solution {
public:
    int removePalindromeSub(string s) {
        //as it only contains a,b and we have to remove a subasequence
        //case 1: s is already a palindrom string moves  = 1;
        //case 2: s is not a palindrom string 1 move for removing all 'a' and 1 for all 'b' total =2;

        if(s.empty())return 0;
        int l = 0;
        int r = s.size()-1;

        while(l<r){
            if(s[l]!=s[r])return 2;
            l++;
            r--;
        }
        return 1;
            
            }
};