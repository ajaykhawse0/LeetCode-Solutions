class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n,-1);
        for(int i=0;i<n;i++){
            int val = nums[i];
            for(int j=0;j<val;j++){
                int temp = j|j+1;
                if(temp==val){
                    arr[i]=j;
                    break;
                }
            }
        }
    return arr;}
};