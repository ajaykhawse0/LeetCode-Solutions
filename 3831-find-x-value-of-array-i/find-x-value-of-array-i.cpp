class Solution {
public:
    typedef long long ll;

    ll solve(int i, ll prod, int req, int k,
             vector<int>& nums,
             vector<vector<ll>>& memo,
             int n) {

        if (i >= n)
            return 0;

        if (memo[i][prod] != -1)
            return memo[i][prod];

        ll skip = 0;

        // Can skip only if subarray has not started
        // prod == k represents "not started"
        if (prod == k) {
            skip = solve(i + 1, prod, req, k, nums, memo, n);
        }

        ll currProd;

        if (prod == k) {
            // Start a new subarray
            currProd = nums[i] % k;
        } 
        else {
            // Extend current subarray
            currProd = (prod * nums[i]) % k;
        }

        ll take = 0;

        if (currProd == req)
            take++;

       
        take += solve(i + 1, currProd, req, k, nums, memo, n);

        return memo[i][prod] = take + skip;
    }

    vector<long long> resultArray(vector<int>& nums, int k) {

        int n = nums.size();

        vector<ll> result(k);

        for (int req = 0; req < k; req++) {

            vector<vector<ll>> memo(
                n,
                vector<ll>(k + 1, -1)
            );

            result[req] = solve(
                0, k, req, k,
                nums, memo, n
            );
        }

        return result;
    }
};