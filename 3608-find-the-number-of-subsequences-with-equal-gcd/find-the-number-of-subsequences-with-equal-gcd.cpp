class Solution {
public: int n;
int MOD = 1e9+7;
    //tle in normal recursion
    //use memoization
     //three params are changing idx,gcd1,gcd2
     vector<vector<vector<int>>>memo;
    int solve(int currIdx,int gcd1,int gcd2,vector<int>&nums){
        if(currIdx == n){
         if(gcd1==0){
            return 0;
         }   
         else if(gcd1==gcd2){
            return 1;//valid seq1,seq2
         }
         else{
            return 0;
         }
        }
        
        if(memo[currIdx][gcd1][gcd2]!=-1)return memo[currIdx][gcd1][gcd2];


        int ans  = 0;

        //now we have three options skip the currIdx in both ,take the currIdx in gcd1,take currIdx in gcd2

        //skipping

        ans = solve(currIdx+1,gcd1,gcd2,nums)%MOD;

        //choosing the curr element in gcd1/seq1;
         
         int newGcd1 = (gcd1==0)?nums[currIdx]:gcd(gcd1,nums[currIdx]);

         ans = (ans + solve(currIdx+1,newGcd1,gcd2,nums))%MOD;
        //choosing the curr element in gcd2/seq2;
         
         int newGcd2 = (gcd2==0)?nums[currIdx]:gcd(gcd2,nums[currIdx]);

         ans =(ans + solve(currIdx+1,gcd1,newGcd2,nums))%MOD;

    
         return memo[currIdx][gcd1][gcd2] =  ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        //constraits are small try with recursion
         
         n = nums.size();
         memo.assign(n+1,vector<vector<int>>(201,vector<int>(201,-1))); 
        return solve(0,0,0,nums);
        
    }
};