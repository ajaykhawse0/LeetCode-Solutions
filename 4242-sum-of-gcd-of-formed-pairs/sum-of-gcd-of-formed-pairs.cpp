class Solution {
public:
    typedef long long ll;
    long long gcdSum(vector<int>& nums) {
        
        vector<int>prefGcd(nums.size(),0);
        int currMax = nums[0];
        for(int i=0;i<nums.size();i++){
            currMax = max(currMax,nums[i]);
            prefGcd[i]=gcd(nums[i],currMax);
        }
        int l=0;
        int r=prefGcd.size()-1;
        sort(begin(prefGcd),end(prefGcd));
        long long sum=0;
        while(l<r){
            sum += (ll)((ll)gcd(prefGcd[l],prefGcd[r]));
        
            l++;
            r--;
        }
    return sum;}
};