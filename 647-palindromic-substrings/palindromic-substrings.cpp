class Solution {
public:
int count  = 0;

    void countAroundCenter(int l,int r,string &s,int n){
        while(l>=0  && r<n && s[l]==s[r]){
            count++;
            r++;
            l--;
        }
    }
    int countSubstrings(string s) {
        int n = s.size();
        for(int i=0;i<n;i++){
            countAroundCenter(i,i,s,n);
            countAroundCenter(i,i+1,s,n);
        };
 return count;   }
};