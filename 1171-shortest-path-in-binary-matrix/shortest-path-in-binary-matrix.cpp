class Solution {
public:
    vector<vector<int>>dirs = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1])return -1;

        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});

        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        
        int ans = INT_MAX;

        while(!q.empty()){
            auto[cost,coor] = q.front();
            auto[r,c] = coor;
            q.pop();

            if(r==n-1 && c==n-1){
                 return cost;
            }
            if(cost>dist[r][c])continue;

            for(auto&dir:dirs){
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0){
                    if(dist[nr][nc]>cost+1){
                        dist[nr][nc] = cost+1;
                    q.push({cost+1,{nr,nc}});}
                }
            }
        }

        return -1;
    }
};