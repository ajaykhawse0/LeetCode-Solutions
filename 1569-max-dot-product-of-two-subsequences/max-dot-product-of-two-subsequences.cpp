class Solution {
public://lcs trick
int m,n;
vector<vector<int>>memo;
    int solve (int i,int j,vector<int>&nums1,vector<int>&nums2){
              if(i==n || j==m)return -1e9;
              
              if(memo[i][j]!=INT_MIN)return memo[i][j];
              int take = nums1[i]*nums2[j];
               
              int takeBothAndContinue = take + solve(i+1,j+1,nums1,nums2); 
              int res=max({
                        takeBothAndContinue,
                        take,//take and stop
                        solve(i+1,j,nums1,nums2),//skip nums1[i]
                        solve(i,j+1,nums1,nums2)//skip nums2[j]
    });

    return memo[i][j]=res;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size();
        memo.assign(n,vector<int>(m,INT_MIN));

        return solve(0,0,nums1,nums2);

    }
};