class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int height = 1;
        int n = parent.size();
        vector<int>depth(n);
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }

        queue<int>q;
        q.push(0);
         depth[0] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto child:adj[node]){
                depth[child] = depth[node]+1;
                height=max(height,depth[child]);
                q.push(child);
            }
        }
        

        long long ans = 0;

        for(int i=0;i<n;i++){
            ans += 1LL*nums[i]*(height-depth[i]+1);
        }
        

        return ans;
    }
};