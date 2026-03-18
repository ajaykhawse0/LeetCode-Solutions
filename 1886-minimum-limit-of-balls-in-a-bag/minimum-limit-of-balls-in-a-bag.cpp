class Solution {
public:
      
      bool possible(vector<int>& nums,int balls , int maxOperations){
        int operations =0;
        for(int&n :nums){
            operations+=(n-1)/balls;
            // operations+=(n)/(balls+1);//both means same thing if balls are equalt to2 and n=4 then if we do n/ba;;s it will 2 but it is happening in one operation only so to maek accurate calculation we decreae n by 1 or increase ball by 1
            if(operations>maxOperations)return false;
        }
        return operations<=maxOperations;     
      }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1, high = *max_element(nums.begin(),nums.end());
        int  mid;
        int ans=high;
        while(low<high){
         mid=low+(high-low)/2;
         if(possible(nums,mid,maxOperations)){
            high=mid;
            ans=high;
         }
         else{
            low=mid+1;
         }
        }

    return ans;}
};