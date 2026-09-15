class Solution {
public:
string str;
    bool isPalindrome(int l,int r){
        while(l < r){
            if(str[l]!=str[r])return false;
            l++;
            r--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        str = s;
        int r = k-1;
        int l = 0;
        int ans = 0;
        int start = 0;

        int n = s.size();

        while(r<n){
            l = r - k + 1;

            if(l >= start && isPalindrome(l,r)){
                ans++;
                start = r+1;
            r++;
                continue; 
            }

            l = r - k;

            if(l >= start && isPalindrome(l,r)){
                ans++;
                start = r+1;
            } 
      r++;
        }
 return ans;   }
};