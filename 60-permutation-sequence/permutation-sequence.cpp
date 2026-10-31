class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums(n);
        iota(nums.begin(),nums.end(),1);
        k--;
        while(k-- && next_permutation(nums.begin(),nums.end()));

        string ans = "";

        for(int i=0;i<n;i++){
            ans += nums[i]+'0';

        }

        return ans;
    }
};