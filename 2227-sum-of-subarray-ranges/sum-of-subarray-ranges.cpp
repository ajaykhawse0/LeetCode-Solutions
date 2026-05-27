class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int maxN=nums[i],minN=nums[i];

            for(int j=i;j<n;j++){
                maxN = max(maxN,nums[j]);
                minN = min(minN,nums[j]);
                sum += (maxN-minN);
            }

        }
      

    return sum;}
};