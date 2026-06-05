class Solution {
public:
    int minimumLength(string s) {
        int l = 0;
        int r = s.size()-1;

        while(l<r){

            if(s[l]==s[r]){
                char c = s[l];
                while(l<=r && s[l]==c){
                    l++;
                }
                while(l<=r && s[r]==c){
                    r--;
                }
            }
            else break;
        }
    
        return r-l+1;
    }
};