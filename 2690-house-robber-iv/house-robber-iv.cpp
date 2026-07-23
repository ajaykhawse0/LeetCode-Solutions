class Solution {
public:
    bool check(int guess,vector<int>&nums,int k){
        int take  = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=guess){
                take++;
                i++;
            if(take>=k)return true;
            }
        }
    return take == k;}
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        
        int ans = -1;
        while (low <= high)
{
            int mid = low + (high-low)/2;

            if(check(mid,nums,k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
    return ans;}
};