class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto&row:image){
            reverse(row.begin(),row.end());
            for(int i=0;i<row.size();i++){
                row[i]=!row[i];
            }
        }
    return image;}
};