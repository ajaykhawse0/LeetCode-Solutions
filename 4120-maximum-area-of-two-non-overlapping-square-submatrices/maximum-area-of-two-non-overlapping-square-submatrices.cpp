class Solution {
public:int m ,n;
    vector<vector<int>>dp;
    int dfs(vector<vector<int>>&mat,int r,int c){
        if(r>=m || c>=n)return 0;

        if(dp[r][c]!=-1)return dp[r][c];

        if(mat[r][c]==0)return 0;

        int down = dfs(mat,r+1,c);
        int right = dfs(mat,r,c+1);
        int diag = dfs(mat,r+1,c+1);

        return dp[r][c] = 1 + min({down,right,diag});
    }
    bool check(int k){
        int minRow = m;
        int maxRow = -1;

        int minCol = n;
        int maxCol = -1;

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(dp[r][c]>=k){
                    minRow = min(minRow,r);
                    maxRow = max(maxRow,r);
                    
                    minCol = min(minCol,c);
                    maxCol = max(maxCol,c);
                }
            }}

        if(maxRow == -1)return false;

        return (maxRow-minRow >=k || maxCol - minCol >= k);
    }
    int maxArea(vector<vector<int>>& mat) {
        //Rec+memo+binary search
         m = mat.size();
         n = mat[0].size();

        dp.assign(m,vector<int>(n,-1));
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                dfs(mat,r,c);
            }
        }

        int low = 0;
        int high = min(m,n);

        int ans = 0;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(check(mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
    return 1LL*ans*ans;}
};