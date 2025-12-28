class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
         int countofnegative=0;
        int row=0,column=m-1;
        while(row< n && column >= 0){
            if(grid[row][column]<0){
                countofnegative+=(n-row);
            column--;
            }
            else{
 row++;
        }
        }
    return countofnegative;}
};