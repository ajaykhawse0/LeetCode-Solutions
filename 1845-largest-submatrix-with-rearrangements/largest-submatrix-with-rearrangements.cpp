class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        //count consecutivve ones in columns 

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }

        //sort by rows and count;
        int res=0;
        for(int i=0;i<m;i++){
            sort(matrix[i].begin(),matrix[i].end(),greater<int>());//decresing order

            for(int width=1;width<=n;width++){
                int height = matrix[i][width-1];
               
               res=max(res,height*width);
            }
        }
    return res;}
};