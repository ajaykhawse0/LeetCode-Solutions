class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.size();
        string ans;
        if(n<=2){
            for(char c:s){
              ans += 'a' + (c-'0' - 1 );
            }
            return ans;
        }
        int i=2;
        int j = 0;
        while(i<n){
            if(s[i]=='#'){
              ans += 'a' + ((s[i-2] - '0') * 10 + (s[i-1] - '0') - 1);
                j=i+1;
                i+=3;
            }
            else{
                ans+= 'a' + (s[j]-'0' - 1 );
                j++;
                i++;
            }
        }
        while(j<n){
             ans+= 'a' + (s[j]-'0' - 1 );
                j++;
        }

    return ans;}
};