class Solution {
public:typedef pair<int,pair<int,int>>P;
vector<vector<int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<P>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        if(grid[0][0]==1){
            q.push({health-1,{0,0}});
        }
        else{
             q.push({health,{0,0}});
        }
        vis[0][0]=1;

        while(!q.empty()){
            int remainHealth = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            
            q.pop();
            
            if(row==m-1 && col == n-1 ){
                if(remainHealth>=1)return true;
            }
            
            for(auto&dir:dirs){
                int nr = row+dir[0];
                int nc = col+dir[1];

                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    grid[nr][nc]==1?q.push({remainHealth-1,{nr,nc}}):q.push({remainHealth,{nr,nc}});
                }
            }

            
             }
   return 0; }
};