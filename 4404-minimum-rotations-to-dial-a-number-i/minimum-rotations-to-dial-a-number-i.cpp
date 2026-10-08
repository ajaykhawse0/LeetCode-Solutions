class Solution {
public:
    int minRotations(string s) {
        int currPos = 0;
        int ans = 0;
        for(char c:s){
            int num = c-'0';
            if(currPos==num)continue;
            int d = (num-currPos+10)%10;
            ans += min(d,10-d);
            currPos = num;
        }
    return ans;}
};