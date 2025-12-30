class Solution {
public:
    bool match(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&patterns){
        
        vector<int>subArray={
            grid[row][col],grid[row][col+1],grid[row][col+2],
            grid[row+1][col],grid[row+1][col+1],grid[row+1][col+2],
            grid[row+2][col],grid[row+2][col+1],grid[row+2][col+2] };
         
         for(auto p : patterns){
          bool matches = true;
            for (int i = 0; i < 9; i++) {
                if (subArray[i] != p[i]) {
                    matches = false;
                    break;
                }
            }
            if (matches) return true;}
    
   return false; }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
         
         if(row<3 || col<3)return 0;
         int cnt=0;

        vector<vector<int>> patterns = {{8, 1, 6, 3, 5, 7, 4, 9, 2},
        {6, 1, 8, 7, 5, 3, 2, 9, 4},
        {4, 9, 2, 3, 5, 7, 8, 1, 6},
        {2, 9, 4, 7, 5, 3, 6, 1, 8},
        {8, 3, 4, 1, 5, 9, 6, 7, 2},
        {4, 3, 8, 9, 5, 1, 2, 7, 6},
        {6, 7, 2, 1, 5, 9, 8, 3, 4},
        {2, 7, 6, 9, 5, 1, 4, 3, 8}
    };

    for(int i=0;i<row-2;i++){
       for(int j = 0 ;j<col-2;j++){
        //Center must be 5;
        if(grid[i+1][j+1]!=5)continue;
        if(match(i,j,grid,patterns))cnt++;
       } 
    }


    return cnt;}
};