class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int top=x;
        
        int bottom = x+k-1;
        int n = y+k;
        while(top<bottom){
            int j=y;
            while(j<n){
            swap(grid[top][j],grid[bottom][j]);
            j++;}
            top++;
            bottom--;
        }
    return grid;}
};