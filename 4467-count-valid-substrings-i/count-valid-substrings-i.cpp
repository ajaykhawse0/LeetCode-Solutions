class Solution {
public:
    long long countValidSubstrings(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();

        long long ans = 0;

        while(r<n){
            if(r>=2 && s[r-2]=='a' && s[r-1]=='b'&&s[r]=='c'){
                l = r-1;
            }
            ans += (r-l+1);
            r++;
        }
    return ans;}
};