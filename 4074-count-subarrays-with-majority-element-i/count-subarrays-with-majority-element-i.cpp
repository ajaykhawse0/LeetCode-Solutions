class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;

        int n = nums.size();
        int cnt = 0;

        for(int i=0;i<n;i++){
            cnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target)cnt++;
                int len = j-i+1;

                if((cnt*2)>len){
                    ans++;
                }
            }
        }
    return ans;}
};