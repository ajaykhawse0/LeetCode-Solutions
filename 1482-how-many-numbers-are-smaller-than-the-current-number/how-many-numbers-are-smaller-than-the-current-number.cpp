class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        //precompute hashmap approach
        vector<int>freq(101,0);
        for(int&n :nums){
            freq[n]++;
        }

        //prefix cumsum

        for(int i=1;i<101;i++){
            freq[i]+=freq[i-1];
        }

        vector<int>ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)continue;
            else{
                ans[i]=freq[nums[i]-1];
            }
        }
    return ans;}

};