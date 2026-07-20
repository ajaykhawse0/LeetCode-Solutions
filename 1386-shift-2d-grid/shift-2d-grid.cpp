class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(!k)return grid;
        int m = grid.size();
        int n = grid[0].size();
        k = k%(m*n);
        if(!k)return grid;

        vector<int>arr;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr.push_back(grid[i][j]);
            }
        }

        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());

        int p = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = arr[p++];
            }
        }


    return grid;}
};
/*
Optimal

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
       //this problem can solved easily by assuming it as a 1D array and k as the no. of right rotations to be made Then transform to 2D  grid again
       if(k==0)return grid;
        int row = grid.size(); 
        int col = grid[0].size();
        int total = row*col;
        k = k % total;

        if(k==0)return grid;

       vector<vector<int>>ans(row,vector<int>(col));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
             //1D Based Array mapping 
             int oldIndex = (i*col+j);
             int newIndex = (oldIndex + k)%total;
             //2D indexing
             int newRow = newIndex/col;
             int newCol = newIndex%col;
             ans[newRow][newCol] = grid[i][j];
            }
        } 
   return ans; }
};

*/