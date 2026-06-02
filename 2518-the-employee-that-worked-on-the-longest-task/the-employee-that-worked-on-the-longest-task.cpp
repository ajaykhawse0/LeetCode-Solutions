class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {

        int ans = logs[0][0];
        int prevTime = 0;
        int maxTime = 0;

        for (auto &log : logs) {

            int id = log[0];
            int leaveTime = log[1];

            int duration = leaveTime - prevTime;

            if (duration > maxTime) {
                maxTime = duration;
                ans = id;
            }
            else if (duration == maxTime) {
                ans = min(ans, id);
            }

            prevTime = leaveTime;
        }

        return ans;
    }
};