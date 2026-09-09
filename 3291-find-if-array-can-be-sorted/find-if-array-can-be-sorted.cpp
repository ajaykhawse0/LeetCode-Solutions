class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>bitsCount(n,0);

        for(int i=0;i<n;i++){
            bitsCount[i] = __builtin_popcount(nums[i]);
        }

        int prevMax = 0;
        int currMin = 0;
        int currMax = 0;

        for(int i=0;i<n;i++){
            currMax = nums[i];
            currMin = nums[i];

            while(i+1 < n && bitsCount[i] == bitsCount[i+1]){
            currMax = max(currMax,nums[i+1]);
            currMin = min(currMin,nums[i+1]);
            i++; 
            }

            if(prevMax <= currMin){
                prevMax = currMax;
            }
            else return false;
        }

 return true;   }
};