class Solution {
public:
    string getPermutation(int n, int k) {
        //we can take help of fact no sytem
        vector<int>fact(n+1,1);

        for(int i=2;i<=n;i++){
            fact[i] = fact[i-1]*i;
        }

        //in permutation we can assume that every no. have d/f fact base

        //first the first num of perm
        vector<int>nums(n);
        iota(nums.begin(),nums.end(),1);
        k--;
        string ans="";

        for(int i=n;i>=1;i--){
           int idx = k/fact[i-1];//this will be used for finding the correct digit at every place

           ans += to_string(nums[idx]);

           nums.erase(nums.begin()+idx);

           k %= fact[i-1];
        }
    return ans;}
};