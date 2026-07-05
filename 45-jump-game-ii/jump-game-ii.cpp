class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;

        if (nums[0] == 0)
            return -1;
        int jumps = 1;
        int currJump = nums[0];
        int maxReach = nums[0];

        for (int i = 1; i < n; i++) {
            if (i == n - 1)
                return jumps;

            maxReach = max(maxReach, i + nums[i]);

            currJump--;

            if (currJump == 0) {
                jumps++;

                // if by chance current index cannoot reached return -1
                if (i >= maxReach)
                    return -1;

                currJump = maxReach - i; // steps left;
            }
        }

        return -1;
    }
};