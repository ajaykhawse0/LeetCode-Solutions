class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        
        vector<vector<pair<int,int>>> dir(7);
        dir[1]={{0,-1},{0,1}};
        dir[2]={{-1,0},{1,0}};
        dir[3]={{0,-1},{1,0}};
        dir[4]={{0,1},{1,0}};
        dir[5]={{0,-1},{-1,0}};
        dir[6]={{0,1},{-1,0}};

        int m = grid.size();  
        int n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({0,0});

        vector<vector<int>> visited(m, vector<int>(n,0));
        visited[0][0] = 1;

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            if(r == m-1 && c == n-1) return true;

            for(auto [dr,dc] : dir[grid[r][c]]){
                int nr = r + dr;
                int nc = c + dc;

                if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc]){
                    
                    // check reverse connection
                    for(auto [ndr,ndc] : dir[grid[nr][nc]]){
                        if(nr + ndr == r && nc + ndc == c){
                            visited[nr][nc] = 1;
                            q.push({nr,nc});
                            break; // important optimization
                        }
                    }
                }
            }
        }
        return false;
    }
};