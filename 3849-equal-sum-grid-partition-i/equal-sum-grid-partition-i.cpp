class Solution {
public:
typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();

        vector<ll>rowSum(m,0),colSum(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            rowSum[i]+=grid[i][j];
            colSum[j]+=grid[i][j];}
        }

         vector<ll>rowPref(m+1,0),colPref(n+1,0);
         for(int i=0;i<m;i++){
            rowPref[i+1] = rowPref[i] + rowSum[i];
         }
         for(int i=0;i<n;i++){
            colPref[i+1] = colPref[i] + colSum[i];
         }

         ll total = colPref[n];//||rowPref[m]

         if(total%2 != 0 )return false;

         ll target = total/2;

         for(int i=0;i<m;i++){
            if(rowPref[i]==target)return true;
         } 
         for(int j=0;j<n;j++){
            if(colPref[j]==target)return true;
         } 

        return false;
    }
};