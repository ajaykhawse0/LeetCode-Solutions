class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,unordered_set<int>>mpp;

        for(vector<int>&log:logs){
            int id = log[0];
            int time = log[1];

            mpp[id].insert(time);
        }
        vector<int>res(k,0);

        for(auto&it:mpp){
            res[it.second.size()-1]++;
        }
 return res;   }
};