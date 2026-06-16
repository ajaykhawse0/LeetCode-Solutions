class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int ans = 0;
        int mx = 0;

        for (int x : nums) {
            if (x >= mx) {
                ++ans;
                mx = x;
            }
        }

        return ans;
    }
};