class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        int l=0;
        int r=0;
        int n = nums.size();
        int sum = 0;

        while(r<n){
            sum += nums[r++];

            if(r-l == k){
                ans = max(ans,(double)sum/k);
                sum -= nums[l++];
                
            }
        }
    return ans;}
};