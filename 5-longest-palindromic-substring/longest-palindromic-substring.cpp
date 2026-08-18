class Solution {
public:int maxlength=1,start=0,n;
       string str;
    void expandAroundCenter(int l,int r ){

        while(l>=0 && r<n && str[l]==str[r]){
            if(r-l+1>maxlength){
                start = l;
                maxlength = r - l + 1; 
            }
            r++;
            l--;
        }
    }
    string longestPalindrome(string s) {
        n = s.size();
        str = s;

        for(int i=0;i<n;i++){
            expandAroundCenter(i,i);
            expandAroundCenter(i,i+1);
        }

        return s.substr(start,maxlength);
    }
};