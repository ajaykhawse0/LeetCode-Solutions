class Solution {
public:typedef pair<int,pair<int,int>>P;
vector<vector<int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<P>q;
        vector<vector<int>>best(m,vector<int>(n,-1));
        
        int startHealth = health-grid[0][0];
        if(startHealth<=0)return false;
        q.push({startHealth,{0,0}});
        best[0][0]=startHealth;
        

        while(!q.empty()){
            int remainHealth = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            
            q.pop();
            
            if(row==m-1 && col == n-1 ){
               
                    cout<<best[row][col];
                    return true;}

            
            if(remainHealth<best[row][col])continue;
            
            for(auto&dir:dirs){
                int nr = row+dir[0];
                int nc = col+dir[1];

                if(nr<0 || nr>=m || nc<0 || nc>=n )continue;

                   int newHealth = remainHealth - grid[nr][nc];

                   if(newHealth>0 && newHealth>best[nr][nc]){
                    best[nr][nc]=newHealth;
                    q.push({newHealth,{nr,nc}});
                   }
                  
                
            }

            
             }
   return 0; }
};