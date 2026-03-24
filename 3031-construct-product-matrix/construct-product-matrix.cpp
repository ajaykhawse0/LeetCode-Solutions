class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int M = 12345;
        int m=grid.size();
        int n = grid[0].size();
      
       vector<vector<int>>p(m,vector<int>(n,1));
        
        long long pref = 1;
        for(int i = 0;i<m;i++){
            for(int j =0 ;j<n;j++){

                p[i][j]=(int)pref;
                pref = (pref*grid[i][j])%M;
            }
        }

        long long suff=1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                p[i][j] = (int)(p[i][j]*suff)%M;
                suff = (suff*grid[i][j])%M;
            }
        }
    return p;}
};