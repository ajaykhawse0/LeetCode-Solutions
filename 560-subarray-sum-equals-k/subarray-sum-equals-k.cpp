class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>pref(n,0);
        pref[0]=nums[0];

        for(int i=1;i<n;i++){
            pref[i] = nums[i] + pref[i-1];
        }

        unordered_map<int,int>mpp;
        int count = 0;

        for(int i=0;i<n;i++){
            if(pref[i]==k)count++;

            int rem = pref[i]-k;

            if(mpp.count(rem)){
                count += mpp[rem];
            }
            mpp[pref[i]]++;
        }
 return count;   }
};