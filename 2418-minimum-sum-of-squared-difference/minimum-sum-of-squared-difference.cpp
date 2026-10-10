class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        //doing -1 in nums1 is equal to +1 in nums2 and vice versa
        //so to find min squared diff we have to perform operation where d/f betn nums1[i] and nums2[i] is max;

        //mx diff possible is 100000-0=>100000
        long long  sum = 0 ;//sum of diffs

        vector<int>diff(1e5+1,0);
        int mxDiff = 0;
        int n = nums1.size();
        for(int i=0;i<n;i++){
              int d = abs(nums1[i]-nums2[i]);
              diff[d]++;
              sum += d;

              mxDiff = max(mxDiff,d);

        }
        
        long long limit = k1+k2;
        if(sum<=limit)return 0;//it is possible to make all differences zero

         // try to shave diff starting from mx one;

         for(int i = mxDiff;i>0;i--){
            long long avail = min(limit,(long long)diff[i]);//avail or maxNeeded which one is minimum

            diff[i] -= avail;
            diff[i-1] += avail;//transfering to other

            limit -= avail;
         }

         //now add the squaured frequency of all the diff's

         long long ans = 0;

         for(int i=1;i<=mxDiff;i++){
            ans += (1LL)*i*i*diff[i];
         }
    return ans;}
};