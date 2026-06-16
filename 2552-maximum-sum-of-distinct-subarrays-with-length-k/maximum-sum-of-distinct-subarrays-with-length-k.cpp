class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;

        long long sum = 0;
        unordered_map<int,int>freq;
        int l=0;
        int r=0;
        int n = nums.size();
        int distinct=0;
        while(r<n){
            sum += nums[r];
            freq[nums[r]]++;
            if(freq[nums[r]]==1){
                distinct++;
            }
            if(r-l+1 > k){
                freq[nums[l]]--;
                if(freq[nums[l]]==0)distinct--;
                sum -= nums[l];
                l++;
            }
            if(r-l+1 == k && distinct==k){
                maxSum=max(maxSum,sum);
            }
            r++;
        }
    return maxSum;}
};