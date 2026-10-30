class Solution {
public:
    long long check(vector<int>& nums,int mid){
        long long cnt = 0;

        for(int n:nums){
            if(n<=0)continue;
            if((n%mid)==0){
                cnt += n/mid;
            }else{
                cnt += (n/mid) + 1;
            }
        }
    return cnt;}
    int minimumK(vector<int>& nums) {
        // nonPositive(nums, k) <= k2

        int low = 1;

        int high = max(
            *max_element(nums.begin(), nums.end()),
            (int)ceil(sqrt(nums.size()))
        );

        int ans = INT_MAX;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(check(nums,mid)<=1LL*mid*mid){
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
    return ans;}
};