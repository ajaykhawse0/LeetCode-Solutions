class Solution {
public: typedef long long ll;
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        ll ans = (ll)nums[0]+(ll)nums[n-1];
        
        ll negSum = 0;
        ll negCnt = 0;
        ll smallestAbs = LLONG_MAX;
        for(int i=1;i<n-1;i++){
             if(nums[i]<0){
                negSum += nums[i];
                negCnt++;


             }
                smallestAbs = min(smallestAbs,abs((ll)nums[i]));
        } 
        ans += negSum;

        if(negCnt & 1) ans += smallestAbs;

        return ans;
    }
};