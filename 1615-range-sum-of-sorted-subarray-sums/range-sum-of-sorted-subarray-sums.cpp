class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        //brute force
    
        vector<long long>arr;
        for(int i = 0;i<n;i++){
            long long pref = 0;

            for(int j = i;j<n;j++){
                pref += nums[j];
                arr.push_back(pref);
            }
        }

        sort(arr.begin(),arr.end());
        int MOD = 1e9+7;
        long long ans = 0;
        for(int i=left-1;i<right;i++){
          ans = (ans+arr[i])%MOD;
        }

        return ans;
    }
};