class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int cnt = 0;
        int curr = nums[0];
        int kCnt = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==curr){
                cnt++;
            }
            else{
                cnt = 1;
                curr = nums[i];
            }
            if(cnt>k){
                nums[i]=102;
                kCnt++;
            }
        }

       
        int n = nums.size();

        int idx = 0;

        for(int i=0;i<n;i++){
            if(nums[i]!=102){
                swap(nums[idx],nums[i]);
                idx++;
            }
        }
        
        nums.resize(n-kCnt);
    return nums;}
};