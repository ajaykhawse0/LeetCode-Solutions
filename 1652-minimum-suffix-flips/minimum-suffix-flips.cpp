class Solution {
public:
    int minFlips(string target) {
        int ans = 0;

        char curr = '0';

        for(char t : target){
            if(t!=curr){
                curr=t;
                ans++;
            }
        }

return ans;
    }
};