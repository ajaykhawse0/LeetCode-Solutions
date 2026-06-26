class Solution {
public:
    typedef long long ll;
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        ll ans =  0;
        int n = nums.size();
        vector<ll>pref(2*n+1,0);
        pref[n] = 1;//n maps to 0 here

        int pointer = n;
        ll currLen = 0;
        for(int num : nums){
            if(num==target){
              currLen += pref[pointer];
              pointer++;
              ++pref[pointer];
            }
            else{
                pointer--; 
                currLen -= pref[pointer];
                pref[pointer]++;
            }

            ans += currLen;
        }
return ans;
    }
};