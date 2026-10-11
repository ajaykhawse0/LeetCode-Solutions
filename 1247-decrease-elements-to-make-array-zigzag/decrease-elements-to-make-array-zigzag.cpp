class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
    
    
        int n = nums.size();
      if(n<=1)return 0;
        int ans = 0;
        int moves1 = 0;
        for (int i = 1; i < n; i += 2) {
            if (i == n - 1) {
                if (nums[i] >= nums[i - 1]) {
                    int diff = nums[i] - nums[i - 1] + 1;
                    moves1 += diff;
                }
            } else {
                if (nums[i] >= nums[i - 1] && nums[i] >= nums[i + 1]) {
                    // d/f between i-1 and i element;
                    int diff = nums[i] - nums[i - 1] + 1;
                    moves1 += diff;

                    if (nums[i] - diff >= nums[i + 1]) {
                        moves1 += nums[i] - diff - nums[i + 1] + 1;
                    }
                } else if (nums[i] >= nums[i - 1]) {
                    int diff = nums[i] - nums[i - 1] + 1;
                    moves1 += diff;

                } else if (nums[i] >= nums[i + 1]) {
                    int diff = nums[i] - nums[i + 1] + 1;
                    moves1 += diff;
                }
            }
        }
        int moves2 = 0;
        for (int i = 0; i < n; i += 2) {

            if (i == 0) {
                if (nums[i] >= nums[i + 1]) {
                    int diff = nums[i] - nums[i + 1] + 1;
                    moves2 += diff;
                }
            } else if (i == n - 1) {
                if (nums[i] >= nums[i - 1]) {
                    int diff = nums[i] - nums[i - 1] + 1;
                    moves2 += diff;
                }
            } else {

                if (nums[i] >= nums[i - 1] && nums[i] >= nums[i + 1]) {
                    // d/f between i-1 and i element;
                    int diff = nums[i] - nums[i - 1] + 1;
                    moves2 += diff;

                    if (nums[i] - diff >= nums[i + 1]) {
                        moves2 += nums[i] - diff - nums[i + 1] + 1;
                    }
                } else if (nums[i] >= nums[i - 1]) {
                    int diff = nums[i] - nums[i - 1] + 1;
                    moves2 += diff;

                } else if (nums[i] >= nums[i + 1]) {
                    int diff = nums[i] - nums[i + 1] + 1;
                    moves2 += diff;
                }
            }
        }
        return min(moves1, moves2);
    }
};