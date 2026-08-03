class Solution {
public:int n ;
   vector<int>memo;
    int solve(int idx,vector<int>& stoneValue){
    if(idx==n)return 0;

    if(memo[idx]!=INT_MIN)return memo[idx];
    int ans = INT_MIN;
    
    //take only one pile
    ans = max(ans,stoneValue[idx] - solve(idx+1,stoneValue));

    // try to take two piles
    if(idx + 1 < n){
    ans = max(ans,stoneValue[idx] + stoneValue[idx+1] - solve(idx+2,stoneValue));
    }
    if(idx + 2 < n){
    ans = max(ans,stoneValue[idx] + stoneValue[idx+1] + stoneValue[idx+2] - solve(idx+3,stoneValue));
    }

    return memo[idx] = ans;
    


    }
    string stoneGameIII(vector<int>& stoneValue) {
        //minimax alice tries to maximize wheras bob tries to minimize
        n = stoneValue.size();
        memo.assign(n,INT_MIN);
        int ans = solve(0,stoneValue);//Alice plays first
        cout<<ans;
        if(ans<0){
            return "Bob";
        }
        else if(ans>0){
            return "Alice";
        }
        return "Tie";
    }
};