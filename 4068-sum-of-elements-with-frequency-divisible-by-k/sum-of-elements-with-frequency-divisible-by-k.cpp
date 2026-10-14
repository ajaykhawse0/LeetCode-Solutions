class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        vector<int>freq(101,0);

        for(int n:nums){
            freq[n]++;

        }
    int ans = 0;
        for(int n:nums){
            if(freq[n]%k==0){
                ans += n;
            }
        }
 return ans;   }
};