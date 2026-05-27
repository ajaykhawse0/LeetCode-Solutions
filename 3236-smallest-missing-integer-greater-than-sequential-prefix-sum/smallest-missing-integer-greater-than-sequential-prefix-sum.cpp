class Solution {
public:
    int missingInteger(vector<int>& nums) {
         unordered_set<int>st(nums.begin(),nums.end());
         int prefixSum=nums[0];
         for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                prefixSum += nums[i];
            }
            else break;
         }
         if(!st.count(prefixSum))return prefixSum;
          
         int i = prefixSum+1; 
         while(true){
          if(!st.count(i))return i;

          i++;
         }
    return 0;}
};