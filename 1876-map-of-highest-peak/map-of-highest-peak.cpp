class Solution {
public:
vector<vector<int>>dirs={{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>>height(m,vector<int>(n,-1));

        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    height[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto[row,col]=q.front();
            q.pop();

            for(auto&dir:dirs){
                int nr = row+dir[0];
                int nc = col+dir[1];

                if(nr>=0 && nr<m && nc>=0 && nc<n && height[nr][nc]==-1){
                    height[nr][nc] = 1+height[row][col];
                    q.push({nr,nc});

                }
            }
        }


    return height;}
};