class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int>pref(n,INT_MAX); 
        vector<int>suff(n,INT_MAX);
        int curr = 0;
        int bestLen = INT_MAX;

        int l = 0;
        int r = 0;

        while(r<n){
            curr += arr[r];
            while(curr>target){
                curr -= arr[l];
                l++;
            }
            if(curr==target)bestLen=min(r-l+1,bestLen);
            pref[r] = bestLen;
            r++;
        }

        l=n-1;
        r=n-1;
        bestLen=INT_MAX;
        curr = 0;
        while(l>=0){
            curr += arr[l];
            while(curr>target && r>=l){
                curr -= arr[r];
                r--;
            }
            if(curr==target)bestLen=min(r-l+1,bestLen);
            suff[l] = bestLen;
            l--;
        }

        int ans = INT_MAX;

        for(int i=0;i<n-1;i++){
            if(pref[i]!=INT_MAX && suff[i+1]!=INT_MAX){
                ans = min(ans,pref[i]+suff[i+1]);
            }
        }

  return ans == INT_MAX ? -1 : ans;  }
};