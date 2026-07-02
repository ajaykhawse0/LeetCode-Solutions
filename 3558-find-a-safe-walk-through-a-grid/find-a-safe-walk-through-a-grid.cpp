class Solution {
public:
typedef pair<int,pair<int,int>>PP;
    vector<vector<int>>dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        int startHealth = health-grid[0][0];
        if(startHealth<=0)return false;
        priority_queue<PP>pq;
        pq.push({startHealth,{0,0}});
        vector<vector<int>>best(m,vector<int>(n,0));
        best[0][0] = startHealth;

        while(!pq.empty()){
            auto[row,col] = pq.top().second;
            int currHealth = pq.top().first;
            pq.pop();

            if(row == m-1 && col == n-1)return true;
            if(currHealth<best[row][col])continue;

            for(auto&dir:dirs){
                int nr = row+dir[0];
                int nc = col+dir[1];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                int newHealth = currHealth - grid[nr][nc];
                
                if(newHealth > 0 && best[nr][nc] < newHealth ){
                    best[nr][nc] = newHealth;

                    pq.push({newHealth,{nr,nc}}); 
                }
                }
            }
        }
  return false;  }
};