class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>>rows(m);
        vector<pair<int,int>>cols(n);

        for(int i=0;i<m;i++){
            int ones=0,zeros=0;
            for(int j=0;j<n;j++){
                 if(grid[i][j]==1)ones++;
                 else zeros++;
            }
            rows[i] = {ones,zeros};
        }
        for(int j=0;j<n;j++){
            int ones=0,zeros=0;
            for(int i=0;i<m;i++){
                 if(grid[i][j]==1)ones++;
                 else zeros++;
            }
            cols[j] = {ones,zeros};
        }

        vector<vector<int>>diff(m,vector<int>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diff[i][j] = rows[i].first + cols[j].first -rows[i].second - cols[j].second;
            }
        }


    return diff;}
};