class Solution {
public:
int m,n;
vector<vector<int>>memo;

    int solve(int i,int j,vector<vector<char>>& matrix){
        if(i>=m || j>=n)return 0;
        if(memo[i][j]!=-1)return memo[i][j];
        if(matrix[i][j]=='0')return memo[i][j] = 0;
       //matrix[i][j]=='1'
       //try all three dirs as we are going from top-down 
        memo[i][j] = min({solve(i,j+1,matrix),solve(i+1,j,matrix),solve(i+1,j+1,matrix)})+1;

        return memo[i][j];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        
        memo.assign(m,vector<int>(n,-1));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans,solve(i,j,matrix));
            }
        }

    return ans*ans;}
};