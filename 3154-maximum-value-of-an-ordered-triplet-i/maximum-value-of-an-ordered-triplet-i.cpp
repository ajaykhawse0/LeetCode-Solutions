class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long mx = 0,maxDiff = 0;
        long long ans = 0;

        for(long long num:nums){
            ans = max(ans,maxDiff*num);
            maxDiff = max(maxDiff,mx - num);
            mx = max(mx,num);
        }

return ans;    }
};