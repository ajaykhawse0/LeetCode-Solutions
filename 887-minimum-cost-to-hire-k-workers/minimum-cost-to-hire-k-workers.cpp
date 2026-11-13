class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        vector<pair<double, int>> wageQualityRatio;

        double cost = DBL_MAX;

        for (int i = 0; i < wage.size(); i++) {
            wageQualityRatio.push_back(
                {(double)wage[i] / quality[i], quality[i]});
        }
        sort(wageQualityRatio.begin(), wageQualityRatio.end());
        priority_queue<int> qualityHeap;
        int qualitytillNow = 0;
        for (int i = 0; i < wage.size(); i++) {

            double ratio = wageQualityRatio[i].first;
            int currQuality = wageQualityRatio[i].second;
            qualitytillNow += currQuality;
            qualityHeap.push(currQuality);

            if (qualityHeap.size() > k) {
                qualitytillNow -= qualityHeap.top();
                qualityHeap.pop();
            }
            if (qualityHeap.size() == k) {
                cost = min(cost, (double)ratio * qualitytillNow);
            }
        }
        return cost;
    }
};