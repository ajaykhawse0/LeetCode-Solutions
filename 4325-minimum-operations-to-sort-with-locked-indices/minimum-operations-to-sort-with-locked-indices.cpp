class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        //use bubble sort
        int reqK = 0;
        int ops = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                if(nums[j]>nums[j+1]){
                    if(locked[j]){
                     locked[j] = 0;
                     reqK++;
                    }
                    if(locked[j+1]){
                     locked[j+1] = 0;
                     reqK++;
                    }

                    if(reqK>k)return -1;

                    swap(nums[j],nums[j+1]);
                    ops++;
                }
            }
        }
  return reqK+ops;  }
};