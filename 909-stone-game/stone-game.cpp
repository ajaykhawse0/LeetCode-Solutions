// class Solution {
// public:
// vector<vector<int>>memo;
//     int solve(vector<int>&piles,int l,int r){
//         if(l==r)return piles[l];

//          if(memo[l][r]!=-1)return memo[l][r];   
 
//         int pickLeft = piles[l] - solve(piles,l+1,r);
//         int pickRight = piles[r] - solve(piles,l,r-1);
 
//         return memo[l][r] =  max(pickLeft,pickRight);


//     }
//     bool stoneGame(vector<int>& piles) {
//         int n = piles.size();
//         memo.assign(n,vector<int>(n,-1));
//         return solve(piles,0,n-1);
//     }
// };

/*O(1) solution
  when observe carefully the array is even length means Alice have two choices whether to choose even idx or odd idx
  for example [5,3,4,5] if he chooses idx 0 => even
  then array will become [3,4,5] bob now can choose odd idx only lets say it chooses idx 1 i.e. 3
  now alice choose idx 3 i.e. 5
  and bob then idx 2 i.e. 4

  so from this we can say that alice always have choices of opposite parity while bob doesn't so if each case alice will win*/

class Solution {
public:
 bool stoneGame(vector<int>&piles){
    return true;
 }
};