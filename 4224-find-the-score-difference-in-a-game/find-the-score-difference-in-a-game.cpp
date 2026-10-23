
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int players[2] = {0};
        int curr = 0;

        for (int i = 0; i < nums.size(); i++) {
            // swap if odd
            if (nums[i] & 1) {
                curr = 1 - curr;
            }

            // swap if its the sixth game
            if ((i + 1) % 6 == 0) {
                curr = 1 - curr;
            }

            players[curr] += nums[i];
        }

        return players[0] - players[1];
    }
};
