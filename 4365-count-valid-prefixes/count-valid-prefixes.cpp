class Solution {
public:
    int countValidPrefixes(string s) {
        //if both are odd not possible;
        int cnt0  = 0;
        int cnt1 = 0;

        // int i=0;
        int j=0;
        int n = s.size();

        int ans = 0;
        while(j<n){
            s[j]=='0'?cnt0++:cnt1++;

            if(abs(cnt0-cnt1)<=1)ans++;
            
            j++;
        }
 return ans;   }
};