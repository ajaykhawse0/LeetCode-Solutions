class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>pq;
        double sum = 0;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            pq.push(nums[i]);
        }

        double target = sum / 2.0;
        int ops = 0;

        while(sum > target && !pq.empty()){
           double val = pq.top();
           pq.pop();

           val = val/2.0;
          
           sum -= val;

           pq.push(val);

           ops++;
        }

        return ops;
    }
};