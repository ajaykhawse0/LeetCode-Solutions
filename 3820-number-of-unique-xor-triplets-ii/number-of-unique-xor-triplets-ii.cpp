class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int mx = 2048;//2^11
        vector<bool>pairXOR(mx,false);
        vector<bool>tripletXOR(mx,false);

        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                pairXOR[nums[i]^nums[j]] = true;
            }
        }
        for(int x=0;x<mx;x++){
            if(pairXOR[x]){
                for(int num:nums){
                    tripletXOR[x^num] = true;
                }
            }
        }
        int ans = 0;

        for(auto t:tripletXOR){
            if(t)ans++;
        }
    return ans;}
};