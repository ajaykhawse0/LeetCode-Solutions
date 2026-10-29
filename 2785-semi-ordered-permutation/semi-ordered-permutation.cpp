class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();

        int idx_1 = 0;
        int idx_n = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                idx_1 = i;
            } else if (nums[i] == n) {
                idx_n = i;
            }
        }
        return (idx_1 < idx_n) ? idx_1 + (n - idx_n - 1)
                               : idx_1 + (n - idx_n - 1) - 1;
    }
};