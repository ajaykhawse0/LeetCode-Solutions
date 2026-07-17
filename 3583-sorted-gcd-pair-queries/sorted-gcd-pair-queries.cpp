class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // calculate freq of each entry
        vector<int> freq(mx + 1, 0);

        for (auto& num : nums) {
            freq[num]++;
        }

        // lets try to compute GCD for all the numbers
        vector<long long> GCD(mx + 1);

            // start from maximum
            for (int i = mx; i >= 1; i--) {
            // count all the num from (0-mx)
            long long count = 0;

            for (int j = 0; j <= mx; j += i) {
                count += freq[j]; // inclusion of all possible pairs
            }

            GCD[i] = count * (count - 1) / 2;

            for (int k = 2 * i; k <= mx; k += i) {
                GCD[i] -= GCD[k]; // exclusion of all covered paireds
            }
        }

        for(int i=1;i<=mx;i++){
            GCD[i] += GCD[i-1];
        }
        int q = queries.size();
        vector<int>ans(q);

        for(int i=0;i<q;i++){
            ans[i] = upper_bound(GCD.begin(),GCD.end(),queries[i])-GCD.begin();
        }
return ans;
    }
};