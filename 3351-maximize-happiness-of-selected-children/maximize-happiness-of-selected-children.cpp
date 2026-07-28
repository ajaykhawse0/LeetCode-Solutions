class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long steps = 0;
        long long ans = 0;

        priority_queue<int>pq(happiness.begin(),happiness.end());

        while(k-- && !pq.empty()){
            if(steps>pq.top())break;
            ans += max(0LL,(pq.top() - steps));
            pq.pop();
            steps++;
        }
    return ans;}
};