/*
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            if(nums[i]<k){
              cnt++;
              st.insert(nums[i]);

            }

        }
        if(cnt==0)return 0;

        for(int i=0;i<n;i++){
            if(!st.count(nums[i]))continue;
            long long  val = nums[i];
            for(int j=i+1;j<n;j++){
                 val *= nums[j];
                 if(val<k){
                    cnt++;
                 }
                 else{
                    break;
                 }


            }
        }
    return cnt;}
};
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
          if(k<=1) return 0;
        int i=0,j=0;
        int n = nums.size();
        long long product = nums[0]; 
        int count = 0;
        while(i<n && j<n){

            if(product<k){
            count += j-i+1;

            if(j<nums.size()-1){
                j++;
            product *= nums[j];
            }
            else {
                break;
            }

            }
            else if(product>=k){
                product = product/nums[i];
                i++;
            }



        }
   return count; }
};