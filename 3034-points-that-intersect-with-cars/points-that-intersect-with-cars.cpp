class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int maxVal = 0;
        map<int, int> Line;
        for (auto& row : nums) {
            Line[row[0]]++;
            Line[row[1] + 1]--; // car will leave next miute to end
            int maxElement = *max_element(row.begin(), row.end());
            maxVal = max(maxVal, maxElement);
        }

        int ans = 0;
        int cnt = 0;

        for (int i = 1; i <= maxVal; i++) {

            if (Line.count(i)) {

                cnt += Line[i];
            }

            if (cnt > 0) {
                ans++;
            }
        }

        return ans;
    }
};