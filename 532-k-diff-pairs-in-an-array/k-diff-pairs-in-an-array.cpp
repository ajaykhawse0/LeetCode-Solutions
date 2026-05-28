class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int& n : nums) {

            freq[n]++;
        }
        int ans = 0;

        for (auto& it : freq) {
            if (k == 0) {
                if (it.second > 1)
                    ans++;
                // reasom a-a = 0;simply as that
            }

            else {
                int need = it.first + k;
                if (freq.count(need)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};