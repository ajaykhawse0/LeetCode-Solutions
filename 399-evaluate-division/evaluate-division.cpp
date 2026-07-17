class Solution {
public:  
unordered_map<string,vector<pair<string,double>>>adj;

void dfs(string& start,string& end,double& ans,double product,unordered_map<string,bool>&vis){
    if(start==end){
        ans = product;
        
        return;
    }
    vis[start] = true;

    for(auto&it:adj[start]){
        string next = it.first;
        double weight = it.second;
        
        if(!vis.count(next)){
            dfs(next,end,ans,product*weight,vis);
        }

    }
}

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
      adj.clear();

        int n = equations.size();

        for(int i=0;i<n;i++){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }

        vector<double>result;

        for(auto&q:queries){
            string start = q[0];
            string end = q[1];

            if(!adj.count(q[0]) || !adj.count(q[1])){
                result.push_back(-1.0);
                continue;
            }
            if(start==end){
                result.push_back(1.0);
                continue;
            }

            double ans = -1.0;
            double product = 1.0;
            unordered_map<string,bool>vis;
            dfs(start,end,ans,product,vis);

            result.push_back(ans);
        }
    return result;}
};