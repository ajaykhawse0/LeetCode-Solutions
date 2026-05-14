class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m,n)/2;

        for(int l=0;l<layers;l++){
            int top = l;
            int left = l;
            int bottom = m-l-1;
            int right = n-l-1;
            
            vector<int>elements;
            //As we have to rotate the layer anticlockwise so we will traverse it clockwise then rotate it accordingly

            //top row
            for(int j=left;j<=right;j++){
               elements.push_back(grid[top][j]);
            }

            //right column
            for(int i=top+1;i<=bottom;i++){
                elements.push_back(grid[i][right]);
            }

            //bottom row
            for(int j=right-1;j>=left;j--){
                elements.push_back(grid[bottom][j]);              
            }
            //left col
            for(int i=bottom-1;i>top;i--){
                elements.push_back(grid[i][left]);              
            }
            int size = elements.size();
            int rotations = k%size;
            
            vector<int>rotated(size);
            for(int i=0;i<size;i++){
                rotated[i]=elements[(i+rotations)%size];
            }
                   int idx=0;
                        //top row
            for(int j=left;j<=right;j++){
               grid[top][j]=rotated[idx++];
            }

            //right column
            for(int i=top+1;i<=bottom;i++){
                grid[i][right]=rotated[idx++];
            }

            //bottom row
            for(int j=right-1;j>=left;j--){
                grid[bottom][j]=rotated[idx++];              
            }
            //left col
            for(int i=bottom-1;i>top;i--){
               grid[i][left]=rotated[idx++];              
            }

        }
return grid;
    }
};