class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mpp;

        int n = nums.size();
        for (int i = 0; i < n; i++) {

            mpp[nums[i]].push_back(i);
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int q = queries[i];

            int val = nums[q];

            auto& arr = mpp[val];
            int size = arr.size();
            if ( size== 1) {
                ans[i] = -1;
                continue;
            }

            int minD = INT_MAX;

            // binary search using lower bound

            auto it = lower_bound(arr.begin(), arr.end(), q);

            int pos = it-arr.begin();

            int prev = arr[(pos-1+size)%size];
            int next = arr[(pos+1)%size];
            
            int diff1 = abs(prev-q);
            int diff2 = abs(next-q);

            minD=min(minD,min(diff1,n-diff1));
            minD=min(minD,min(diff2,n-diff2));


            ans[i] = minD;
        }
        return ans;
    }
};