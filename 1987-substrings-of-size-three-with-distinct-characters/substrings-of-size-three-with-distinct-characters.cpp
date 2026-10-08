class Solution {
public:
    int countGoodSubstrings(string s) {
        char a = s[0],b = s[1],c = s[2];
        int res = 0;
        for(int i=3;i<s.size();i++){
            if(a!=b && b!=c && c!=a)res++;
            a = b;
            b = c;
            c = s[i];
        }
            if(a!=b && b!=c && c!=a)res++;

return res;
    }
};