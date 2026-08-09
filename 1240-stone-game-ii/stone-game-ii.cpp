class Solution {
public://Alice is player 0 and bob is 1
vector<vector<vector<int>>>memo;
int n;
    // n-i
    int solve(int player,int idx,int M,vector<int>&piles){
        if(idx >= n)return 0;

        if(memo[player][idx][M]!=-1)return memo[player][idx][M];

        int res = (player==0)?0:INT_MAX;
        int stoneSum = 0;
        for(int x=1;x<=min(2*M,n-idx);x++){
            stoneSum += piles[idx+x-1];
            if(player==0){
                res = max(res,stoneSum+solve(1,idx+x,max(x,M),piles));
            }
            else{
                res = min(res,solve(0,idx+x,max(x,M),piles));
            }
        }

           return memo[player][idx][M] = res; }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memo.assign(2,vector<vector<int>>(n,vector<int>(n+1,-1)));
         

        return solve(0,0,1,piles);
    }
};