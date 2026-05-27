class Solution {
public:
    typedef pair<int,int> P;

    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {

        int n = reward1.size();

        int ans = accumulate(reward2.begin(), reward2.end(), 0);

        priority_queue<P, vector<P>, greater<P>> minHeap;

        for (int i = 0; i < n; i++) {

            int diff = reward1[i] - reward2[i];

            minHeap.push({diff, i});

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        while (!minHeap.empty()) {

            int idx = minHeap.top().second;

            ans += (reward1[idx] - reward2[idx]);

            minHeap.pop();
        }

        return ans;
    }
};