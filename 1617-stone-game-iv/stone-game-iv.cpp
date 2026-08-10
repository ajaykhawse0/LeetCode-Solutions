class Solution {
public:vector<vector<int>>memo;
    bool solve(int n,bool isAlice){
        
        int idx = isAlice?1:0;
        if(memo[n][idx]!=-1){
            return memo[n][idx];
        }

        bool best = !isAlice;

                for(int i=1;i*i<=n;i++){
            if(isAlice){
                if(solve(n-i*i,false)){
                    best = true;
                    break;
                }


            }
            else{
                if(!solve(n-i*i,true)){
                    best =  false;
                    break;
                }
            }
        }
    return memo[n][idx] = best?1:0;}
    bool winnerSquareGame(int n) {
        memo.assign(n+1,vector<int>(2,-1));
        return solve(n,true);
    }
};