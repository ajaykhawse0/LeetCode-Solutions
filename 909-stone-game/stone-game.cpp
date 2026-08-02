class Solution {
public:
vector<vector<int>>memo;
    int solve(vector<int>&piles,int l,int r){
        if(l==r)return piles[l];

         if(memo[l][r]!=-1)return memo[l][r];   
 
        int pickLeft = piles[l] - solve(piles,l+1,r);
        int pickRight = piles[r] - solve(piles,l,r-1);
 
        return memo[l][r] =  max(pickLeft,pickRight);


    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memo.assign(n,vector<int>(n,-1));
        return solve(piles,0,n-1);
    }
};