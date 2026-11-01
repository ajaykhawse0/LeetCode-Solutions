class Solution {
public:int digs(int n){
    int cnt = 0;
    while(n>0){
        cnt++;
        n/=10;
    }
    return cnt;
}
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=0;i<n-1;i+=2){
              int d = digs(nums[i+1]);

              ans = min(ans,(int)(nums[i]*pow(10,d)+nums[i+1]));
        }
    return ans;}
};