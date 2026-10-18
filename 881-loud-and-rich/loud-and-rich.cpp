class Solution {
public:
    unordered_map<int,vector<int>>richNess;
    vector<int>res;
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
         for(auto&r:richer){
            richNess[r[1]].push_back(r[0]);
         }

         int n = quiet.size();
          res.assign(n,-1);
         for(int i=0;i<n;i++){
               res[i] = dfs(i,quiet);
         }
    return res;}

    int dfs(int currPerson,vector<int>&quiet){
        if(res[currPerson]>=0)return res[currPerson];
        res[currPerson] = currPerson;//temp;

        for(int richerPerson:richNess[currPerson]){
                if(quiet[res[currPerson]]>quiet[dfs(richerPerson,quiet)]){
                    res[currPerson] = res[richerPerson];
                }
        }
    return res[currPerson];}
};