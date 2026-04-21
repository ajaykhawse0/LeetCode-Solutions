class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> lastIdx;
        int ans = INT_MAX;

        for (int i = nums.size()-1; i >=0; i--) {
            int rev = reverseNum(nums[i]);

            if (lastIdx.count(rev)) {
                ans = min(ans, lastIdx[rev]-i);
            }

            lastIdx[nums[i]] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};