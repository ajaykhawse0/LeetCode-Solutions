class Solution {
public:
    int secondHighest(string s) {
        int mn = -1;
        int mx = -1;

        for(char c:s){
            if(isdigit(c)){
                int n = c-'0';
                if(n==mx)continue;
                if(n>mx){
                    mn=mx;
                    mx=n;
                }
                else{
                    mn = max(mn,n);
                }
            }
        }

        return mn;
    }
};