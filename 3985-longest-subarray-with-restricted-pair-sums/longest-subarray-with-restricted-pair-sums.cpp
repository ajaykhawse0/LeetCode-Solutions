class Solution {
public:
    bool check(int l,int r,vector<int>& nums){
        vector<int>freq(501,0);
        for(int i=l;i<=r;i++){
            freq[nums[i]]++;
        }

        for(int i=1;i<=500;i++){
            if(freq[i]<=0)continue;
            freq[i]--;

            for(int j=1;j<=500;j++){
                if(freq[j]<=0)continue;
                freq[j]--;

                int val = i+j;

                if(val<=500 && freq[val]>0)return true;

                freq[j]++;
            }
            freq[i]++;
        }

        return false;

    }
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();

        int ans = min(2,n);
        int r = 2;

        int l = 0;

        while(r<n){
            if(check(l,r,nums)){
                l++;
                r++;
            }
            else{
                ans = max(ans,r-l+1);
                r++;
            }
        }
    return ans;}
};