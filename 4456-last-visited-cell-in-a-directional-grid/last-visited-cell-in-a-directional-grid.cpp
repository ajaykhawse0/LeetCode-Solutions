class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>>vis(m,vector<bool>(n,false));

        int r = 0;
        int c = 0;

        vis[0][0] = true;

        while(true){
            char d = grid[r][c];
            int nr = r , nc = c;

            if(d=='U')nr--;
            else if(d=='D')nr++;
            else if(d=='L')nc--;
            else if(d=='R')nc++;

            if(nr<0 || nr>=m || nc<0 || nc >= n || vis[nr][nc])return {r,c};
            vis[nr][nc]=1;

            r = nr;
            c = nc;
        }
 return {};   }
};
