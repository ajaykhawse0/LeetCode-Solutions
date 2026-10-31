class Solution {
public:
    vector<vector<int>> jobs;
    vector<int> memo;
    int n;
    int solve(int curr) {
        if (curr >= n)
            return 0;

        if (memo[curr] != -1)
            return memo[curr];

        auto it = lower_bound(jobs.begin(), jobs.end(), jobs[curr][1],
                              [](const vector<int>& job, int endTime) {
                                  return job[0] < endTime;
                              });

        int next = it - jobs.begin();
        int take = jobs[curr][2] + (next == -1 ? 0 : solve(next));

        int skip = solve(curr + 1);

        return memo[curr] = max(skip, take);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        n = profit.size();
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        memo.assign(n, -1);

        sort(jobs.begin(), jobs.end());

        return solve(0);
    }
};