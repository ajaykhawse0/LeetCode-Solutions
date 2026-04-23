class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
          mpp[nums[i]].push_back(i);
        }

        vector<long long>ans(n);

        for(auto&it:mpp){
            vector<int>indices = it.second;

            long long sum = 0;

            for(int val:indices){
                sum += val;
            }

            long long leftSum = 0;

            int m = indices.size();

            for(int i=0;i<m;i++){

                long long rightSum = sum - indices[i] - leftSum;

                long long left = 1LL*indices[i]*i - leftSum;
                long long right =rightSum  - 1LL*indices[i]*(m-i-1);

                ans[indices[i]] = left+right; 

                leftSum += indices[i];


            }
        }

    return ans;}
};