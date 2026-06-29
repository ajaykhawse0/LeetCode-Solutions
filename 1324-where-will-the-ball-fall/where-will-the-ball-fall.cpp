class Solution {
public:
int row,col;
    
    bool validate(int r,int c){
        if(row <= r || col <= c || r<0 || c<0)return false;

        return true;
    }

    int dfs(vector<vector<int>>&grid,int r,int c){
        if(r==row)return c;

        if(grid[r][c] == 1){
            //try to move to next right diagonal
            if(validate(r,c+1) && grid[r][c+1] == 1){
                return dfs(grid,r+1,c+1);
            }
        }

        else{
            //try to move to left diagonal
            if(validate(r,c-1) && grid[r][c-1] == -1){
                return dfs(grid,r+1,c-1);
            }
        }
return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        vector<int>result(col,0);

        for(int i=0;i<col;i++){
            result[i] = dfs(grid,0,i);
        }
        return result;
    }
};