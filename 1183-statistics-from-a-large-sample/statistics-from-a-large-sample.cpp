class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int minVal = INT_MAX;
        double maxVal = -1;
        double mode = 0;
        long long total = 0;
        long long cnt = 0;
        int freq = 0;

        for (int i = 0; i <= 255; i++) {
            if (count[i] > 0) {
                minVal = min(minVal, i);
                maxVal = i;
                cnt += count[i];

                total += 1LL * count[i] * i;

                if (freq < count[i]) {
                    freq = count[i];
                    mode = i;
                }
            }
        }

        double mean = (double)total / cnt;

        long long leftPos = (cnt + 1) / 2;
        long long rightPos = (cnt + 2) / 2;
        long long m1 = -1;
        long long m2 = -1;
        long long running = 0;
        for (int i = 0; i < 256; i++) {
            running += count[i];
            if (running >= leftPos && m1 == -1) {
                m1 = i;
            }
            if (running >= rightPos && m2 == -1) {
                m2 = i;
                break;
            }
        }
        double median = (double)(m1 + m2) / 2;

        return {(double)minVal, maxVal, mean, median, mode};
    }
};