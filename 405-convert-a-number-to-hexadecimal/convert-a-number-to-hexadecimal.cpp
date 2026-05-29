class Solution {
public:
    string toHex(int num) {
        unsigned int givenNum = num;
        // -1 maps to 2^31 - 1

        string s = "0123456789abcdef";

        string ans="";

        do{
            ans += s[givenNum%16];
            givenNum /= 16;
        }
        while(givenNum);
        reverse(ans.begin(),ans.end());
return ans;
    }
};