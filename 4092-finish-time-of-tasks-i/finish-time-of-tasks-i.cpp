class Solution {
public: using ll = long long;
    
    ll solve(int curr,vector<vector<int>>&adj,vector<int>& baseTime){
        if(adj[curr].empty())return baseTime[curr];

        long long  latest  = 0;
        long long  earliest  = LLONG_MAX;

        for(auto & it : adj[curr]){
            ll a = solve(it,adj,baseTime);

             latest  = max( latest ,a);
             earliest  = min( earliest ,a);

        }

        ll own = ( latest - earliest ) + baseTime[curr];
        
        ll finishTime =  latest  + own;

        return finishTime;
    }

    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>>adj(n);

        for(auto&edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }

        return solve(0,adj,baseTime);
    }
};