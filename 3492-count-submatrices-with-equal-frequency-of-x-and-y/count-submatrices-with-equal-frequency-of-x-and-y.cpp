class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>prefX(m+1,vector<int>(n+1,0));
        vector<vector<int>>prefY(m+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                prefX[i+1][j+1]=(grid[i][j]=='X')?1:0;
                prefY[i+1][j+1]=(grid[i][j]=='Y')?1:0;

                prefX[i+1][j+1] += prefX[i][j+1] + prefX[i+1][j] - prefX[i][j] ;
                prefY[i+1][j+1] += prefY[i][j+1] + prefY[i+1][j] - prefY[i][j] ;

                if(prefX[i+1][j+1]==prefY[i+1][j+1]  && prefX[i+1][j+1]>0)ans++;
            }
        }

        return ans;


    }
};