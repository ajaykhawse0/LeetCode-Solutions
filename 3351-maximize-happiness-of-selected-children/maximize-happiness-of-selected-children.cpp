class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum =0;
       priority_queue<int> maxHeap(happiness.begin(), happiness.end());
        long long turns =0;
        while(k>0 && !maxHeap.empty()){
            long long val = maxHeap.top();
            // cout<<val;
            maxHeap.pop();
           
            long long effectiveTurns = max(0LL, val - turns);
            sum += effectiveTurns;
             turns++;
            k--;


        }
    return sum;}
};