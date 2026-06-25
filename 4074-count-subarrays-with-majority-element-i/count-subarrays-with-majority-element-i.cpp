class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {

            pref[i + 1] = pref[i] + (target == nums[i] ? 1 : -1);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (pref[j + 1] - pref[i] > 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};