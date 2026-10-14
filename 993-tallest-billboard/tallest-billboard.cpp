class Solution {
public:vector<vector<int>>memo;
int n;
    int solve(int i,int diff,vector<int>&rods){
        if(i==n){
return (diff==0 ? diff : INT_MIN/2 );
        }
        int &ans = memo[i][diff+5000];

        if(ans!=-1)return ans;

        //skip the curr rod
        ans = solve(i+1,diff,rods);
        //add rod to pole one(tallest)
        ans = max(ans,solve(i+1,diff+rods[i],rods));
        //add rod to pole two(shortest)
        int res = solve(i+1,diff-rods[i],rods);

        if(res > INT_MIN/2){
            ans = max(ans,res+rods[i]);
        }
  

        return ans;

}
    int tallestBillboard(vector<int>& rods) {
         n = rods.size();
        memo.assign(n,vector<int>(10001,-1));

        return solve(0,0,rods);
    }
};