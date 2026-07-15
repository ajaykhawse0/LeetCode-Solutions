class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mpp;
        for(int i=0;i<grid.size();i++){
            mpp[grid[i]]++;
        }
        int cnt=0;
        for(int j=0;j<grid.size();j++){
            vector<int>temp;
            for(int i=0;i<grid.size();i++){
              temp.push_back(grid[i][j]);
            }
            if(mpp.count(temp))cnt+=mpp[temp];
        }
    return cnt;}
};