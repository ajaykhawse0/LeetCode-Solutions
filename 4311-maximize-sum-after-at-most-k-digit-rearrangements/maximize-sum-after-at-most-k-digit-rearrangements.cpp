class Solution {
public:
    using T = tuple<long long, long long, long long>;
    long long rearrange(long long n) {
        long long freq[10] = {};

        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }

        long long ans = 0;

        for (long long d = 9; d >= 0; d--) {
            while (freq[d]--) {
                ans = ans * 10 + d;
            }
        }

        return ans;
    }
    long long maximizeSum(vector<int>& nums, int k) {
        priority_queue<T> pq;

        for (int num : nums) {
            long long largest = rearrange(num);
            long long diff = largest - num;
            pq.push({diff, largest, num});
        }
        long long ans = 0;
        while (k-- && !pq.empty()) {
            auto [diff, lar, ori] = pq.top();
            pq.pop();
            ans += lar;
        }

        while (!pq.empty()) {
            auto [diff, lar, ori] = pq.top();
            pq.pop();
            ans += ori;
        }
        return ans;
    }
};