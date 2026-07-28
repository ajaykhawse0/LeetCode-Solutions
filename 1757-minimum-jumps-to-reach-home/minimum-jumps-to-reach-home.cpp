class Solution {
public:
    unordered_set<int>forbi;
    vector<vector<int>>memo;
    vector<vector<bool>>vis;
    int INF = 1e9;
    int solve(int curr,int a,int b,int x,int backward){
        if(curr==x)return 0;

        if(curr<0 || curr>6000 || backward>=2 || forbi.count(curr)){
            return INF;
        }
        if (vis[curr][backward])
    return INF;

        if(memo[curr][backward]!=-1)return memo[curr][backward];
        int ans = INF;

      //move forward
       
       vis[curr][backward] = true;
       ans = min(ans,1+solve(curr+a,a,b,x,0));

       if(!backward){
        //move backwards

        ans = min(ans,1+solve(curr-b,a,b,x,1));
       }
        
       vis[curr][backward] = false;
       return memo[curr][backward]=ans;

    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        forbi.clear();
        for(int &f:forbidden){
            forbi.insert(f);
        }

        //Total forward and backward 2000 each and 2000 points of forbiden maxPossible = 2000+2000+2000 = 6000;
        memo.assign(6001,vector<int>(2,-1));
        vis.assign(6001,vector<bool>(2,false));
        int ans = solve(0,a,b,x,0);

        return ans >= INF?-1:ans;
    }
};