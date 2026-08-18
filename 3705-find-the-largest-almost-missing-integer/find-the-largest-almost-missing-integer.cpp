class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        //If 1 < k < n, all elements different from nums[0] and nums[n - 1] will occur in more than one subarray of size k. Hence, the answer is the largest of nums[0] and nums[n - 1] if they both occur exactly once in the array. If one of them occurs more than once, return the other. If both of them occur more than once, return -1

        vector<int>freq(51,0);

        for(int &i:nums){
            freq[i]++;
        }
        int n = nums.size();
        if(k==n){
            return *max_element(nums.begin(),nums.end());

        }

        if(k==1){
            int mx = -1;
            for(int i=0;i<n;i++){
                if(freq[nums[i]]==1 && nums[i]>mx){
                    mx = nums[i];
                }

            }
            return mx;
        }

        if(nums[0]==nums[n-1])return -1;

        if(freq[nums[0]] == 1 && freq[nums[n-1]] == 1)return max(nums[0],nums[n-1]);

        if(freq[nums[0]] == 1 && freq[nums[n-1]] > 1)return nums[0];
        if(freq[nums[0]] > 1 && freq[nums[n-1]] == 1)return nums[n-1];

        return -1;
    }
};