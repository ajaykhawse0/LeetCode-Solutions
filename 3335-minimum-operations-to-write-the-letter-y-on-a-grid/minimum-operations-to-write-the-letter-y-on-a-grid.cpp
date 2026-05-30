class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {

        int n = grid.size();
        int mid = n / 2;
        vector<int> countY(3, 0);
        vector<int> countOther(3, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Condition for cells belonging to 'Y'
                if ((i < mid && (i == j || i + j == n - 1)) ||
                    (i >= mid && j == mid)) {
                    countY[grid[i][j]]++;
                } else {
                    countOther[grid[i][j]]++;
                }
            }
        }
        // for(int i=0;i<3;i++){
        //     cout<<"cnt : "<<i<<" Y :"<<countY[i]<<endl;
        //     cout<<"cnt : "<<i<<" : "<<countOther[i]<<endl;
        // }

        int minOperation=INT_MAX;
        
        for(int y =0 ;y<3;y++){
            for(int other = 0;other<3;other++){
                if(y!=other){
                    int operation = ((n*n - countY[y])-countOther[other]);

                    minOperation=min(minOperation,operation);
                }
            }
        }

        return minOperation;
    }
};