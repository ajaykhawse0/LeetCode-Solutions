class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //REv
      //1st Approach
        int n = nums.size();
        vector<int> ans(n);
        // vector<int> positive;

        // vector<int> negative;

        // for (auto& num : nums) {
        //     if (num >= 0) {
        //         positive.push_back(num);
        //     } else {
        //         negative.push_back(num);
        //     }
        // }
        // int p=0,neg=0;

        // for (int i = 0; i < n; i++) {
        //     if (i % 2 == 0) {
        //         ans[i] = positive[p];
        //         p++;
        //     } else {
        //         ans[i] = negative[neg];
        //         neg++;
        //     }
        // }
        // return ans;

        //2nd Approach

        int pos=0,neg=1;

        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                ans[pos]=nums[i];
                pos+=2;
            }
            else {
                ans[neg]=nums[i];
                neg+=2;
            }
        }
   return ans; }
};