class Solution {
public:
    int countHomogenous(string s) {
        int MOD=1e9+7;
        int res=0;
        int currCount=0;
        char curr;
        for(char c:s){
           currCount = c==curr?currCount+1:1;
           curr = c;

           res = (res+currCount)%MOD;
        }
return res%MOD;
    }
};