class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
        int i=0;
        int maxLen = 0;
        int n = nums.size();

        for(int j=0;j<n;j++){

            while((long long)nums[j] > (long long)nums[i]*k){
                i++;
            }

            maxLen = max(maxLen,j-i+1);
        }
    return n-maxLen;}
};