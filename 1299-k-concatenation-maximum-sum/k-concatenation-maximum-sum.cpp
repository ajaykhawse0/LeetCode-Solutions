class Solution {
public:
    int kConcatenationMaxSum(vector<int>& nums, int k) {
        long long maxSoFar=0;
        int MOD=1e9+7;
        long long maxEndingHere=0;
        long long sum =  accumulate(nums.begin(),nums.end(),0LL);
        int n = nums.size();
        for(int i=0;i<min(2,k)*n;i++){
            maxEndingHere=max((long long)nums[i%n],maxEndingHere+nums[i%n]);
            maxSoFar=max(maxSoFar,maxEndingHere);
        }
        long long addition = max(0LL,sum)*max(0,k-2);
    return (maxSoFar+addition)%MOD;}
};