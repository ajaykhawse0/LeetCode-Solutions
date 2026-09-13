class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long ans = LLONG_MIN;
        int n = nums.size();
        vector<long long>pref(n,0);

        pref[0] = nums[0];
        for(int i=1;i<n;i++){
            pref[i] += pref[i-1] + nums[i];
        }

        vector<int>suffMin(n);
        suffMin[n-1] = nums[n-1];

        for(int i=n-2;i>=0;i--){
            suffMin[i] = min(suffMin[i+1],nums[i]);
        }

        for(int i=0;i<n-1;i++){
          ans = max(ans,pref[i]-suffMin[i+1]);
        }

        return ans;
    }
};