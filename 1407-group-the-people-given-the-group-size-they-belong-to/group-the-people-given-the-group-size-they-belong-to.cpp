class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>>mpp;
        for(int i=0;i<groupSizes.size();i++){
            mpp[groupSizes[i]].push_back(i);
        }
        
        vector<vector<int>>ans;

        for(auto&[sz,grp]:mpp){
            int ptr = 0;
            int n = grp.size();

            int totalGrp = n/sz;
            int sze = sz;
            for(int i=0;i<totalGrp;i++){
                vector<int>arr;
                for(ptr;ptr<sze;ptr++){
                   arr.push_back(grp[ptr]);
                }
                sze += sz;
                ans.push_back(arr);
            }

        }
    return ans;}
};