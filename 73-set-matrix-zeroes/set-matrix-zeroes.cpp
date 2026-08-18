class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        bool firstRow = false,firstCol = false;

        for(int j=0;j<n;j++){
            if(mat[0][j]==0){
                firstRow = true;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(mat[i][0]==0){
                firstCol = true;
                break;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0)continue;
                if(mat[i][j]==0){
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][0]==0 || mat[0][j]==0){
                    mat[i][j] = 0;
                }
            }
        }

        if(firstRow){
            for(int i=0;i<n;i++){
                mat[0][i] = 0;
            }
        }
        if(firstCol){
            for(int i=0;i<m;i++){
                mat[i][0] = 0;
            }
        }
    }
};