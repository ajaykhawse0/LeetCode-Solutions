
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1,
                            vector<int>& nums2, int k) {
        unordered_map<int, int> freq;

        for (int x : nums2) {
            freq[x]++;
        }

        long long res = 0;

        for (int a : nums1) {
            if (a % k != 0) continue;

            int x = a / k;

            for (int d = 1; 1LL * d * d <= x; d++) {
                if (x % d != 0) continue;

                // d is a divisor of x
                res += freq[d];

                // x / d is the paired divisor
                if (d != x / d) {
                    res += freq[x / d];
                }
            }
        }

        return res;
    }
};
