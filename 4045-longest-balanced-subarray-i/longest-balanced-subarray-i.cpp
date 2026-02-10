class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> stOdd;
            unordered_set<int> stEven;
            
            for(int j=i;j<n;j++){

                if(nums[j]&1){
                    stOdd.insert(nums[j]);
                }
                else{
                    stEven.insert(nums[j]);
                }
                if(stOdd.size()==stEven.size()){
                maxLen = max(maxLen,j-i+1);}
            }
        }
 return maxLen;   }
};