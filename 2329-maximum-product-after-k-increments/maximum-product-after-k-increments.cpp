class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int MOD=1e9+7;
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());

        while(k-- && !pq.empty()){
            int val = pq.top();
            pq.pop();
            pq.push(val+1);


        }

        long long ans = 1;

        while(!pq.empty()){
            ans = (ans*pq.top())%MOD;
            pq.pop();
        }

        return ans%MOD;
    }
};