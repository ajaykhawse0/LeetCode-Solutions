class Solution {
public:
    int minOperations(int k) {
        if(k==1)return 0;
        int val = 1;
        int operations=0;
        int ans = INT_MAX;
       for (int val = 1; val <= k; val++) {
            int cnt = (k + val - 1) / val; // ceil(k / val)
            ans = min(ans, (val - 1) + (cnt - 1));
        }
 return ans;   }
};