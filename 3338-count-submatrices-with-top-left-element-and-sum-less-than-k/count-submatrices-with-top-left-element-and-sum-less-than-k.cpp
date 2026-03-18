class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>cumSum(m+1,vector<int>(n+1,0));

        //formula for cumsum
        /*
        cumSum[i+1][j+1] = cumSum[i][j+1]+cumSum[i+1][j]+grid[i][j]-cumSum[i][j]
       =>Sum of all elements on top + Sum of all elements in left + current Value - (subtract the top leftmost element as it as counted twice[in top and left sum both])
        */
        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                cumSum[i+1][j+1] = cumSum[i][j+1] + cumSum[i+1][j] + grid[i][j] - cumSum[i][j];

                if(cumSum[i+1][j+1]<=k)cnt++;//if the current CumSum is lesser than k it satisfies condition 
            }
        }
    return cnt;}
};