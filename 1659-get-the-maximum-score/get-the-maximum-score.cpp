// class Solution {
// public:

//     const int MOD = 1e9 + 7;

//     unordered_map<int,int> pos1, pos2;

//     vector<long long> dp1, dp2;

//     long long dfs(int arr, int idx,
//                   vector<int>& nums1,
//                   vector<int>& nums2) {

//         if (arr == 0) {

//             if (idx >= nums1.size())
//                 return 0;

//             if (dp1[idx] != -1)
//                 return dp1[idx];

//             long long takeSame =
//                 nums1[idx] + dfs(0, idx + 1, nums1, nums2);

//             long long ans = takeSame;

//             // can switch ?
//             if (pos2.count(nums1[idx])) {

//                 int j = pos2[nums1[idx]];

//                 ans = max(ans,
//                           nums1[idx] + dfs(1, j + 1, nums1, nums2));
//             }

//             return dp1[idx] = ans;
//         }

//         else {

//             if (idx >= nums2.size())
//                 return 0;

//             if (dp2[idx] != -1)
//                 return dp2[idx];

//             long long takeSame =
//                 nums2[idx] + dfs(1, idx + 1, nums1, nums2);

//             long long ans = takeSame;

//             // can switch ?
//             if (pos1.count(nums2[idx])) {

//                 int j = pos1[nums2[idx]];

//                 ans = max(ans,
//                           nums2[idx] + dfs(0, j + 1, nums1, nums2));
//             }

//             return dp2[idx] = ans;
//         }
//     }

//     int maxSum(vector<int>& nums1, vector<int>& nums2) {

//         for (int i = 0; i < nums1.size(); i++)
//             pos1[nums1[i]] = i;

//         for (int i = 0; i < nums2.size(); i++)
//             pos2[nums2[i]] = i;

//         dp1.assign(nums1.size(), -1);
//         dp2.assign(nums2.size(), -1);

//         long long ans1 = dfs(0, 0, nums1, nums2);
//         long long ans2 = dfs(1, 0, nums1, nums2);

//         return max(ans1, ans2) % MOD;
//     }
// };


//GREEDY APPROACH

class Solution{
    public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m=nums2.size();
        long long  MOD = 1e9+7;
        long long  sum1=0;
        long long  sum2=0;

        int i=0,j=0;

        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                sum1 += nums1[i] % MOD;
                i++;
            }
            else if(nums1[i]>nums2[j]){
                sum2 += nums2[j] % MOD;
                j++;
            }
            else {
                //same wala case can change path
                long long best = (max(sum1,sum2)+nums1[i])%MOD;//best answer wit or without change

                sum1=best;
                sum2=best;

                i++;
                j++;
                
            }
        }
        while(i<n){
            sum1 += nums1[i] % MOD;
                i++;
        }
        while(j<m){
            sum2 += nums2[j] % MOD;
                j++;
        }

    return (max(sum1,sum2)%MOD);}
};

