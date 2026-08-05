class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        //a method can only be removed if it is invoked by an sus method;

        vector<vector<int>>adj(n);

        for(auto&inv:invocations){
            adj[inv[0]].push_back(inv[1]);
        }

        vector<bool>sus(n,false);
        queue<int>q;
        sus[k] = true;
        q.push(k);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nei : adj[node]){
                if(!sus[nei]){
                    sus[nei] = true;
                    q.push(nei);
                }
            }
        }

        for(auto&inv:invocations){
            int u = inv[0];
            int v = inv[1];

            if(!sus[u] && sus[v]){
                //condition voilated can't remove any method

                vector<int>ans(n);//will have all methods

                iota(ans.begin(),ans.end(),0);
                 return ans;
            }
        }

        vector<int>res;
        for(int i=0;i<n;i++){
            if(!sus[i]){
                res.push_back(i);
            }
        }
 return res;   }
};