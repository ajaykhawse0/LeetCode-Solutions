class Solution {
public:
int n ;

vector<vector<int>>memo;
    int solve(vector<int>&obstacles,int curr,int lane){
        
        if(curr==n){
            return 0;
        }
        if(memo[curr][lane]!=INT_MIN)return memo[curr][lane];
        if(obstacles[curr+1]!=lane){
         return solve(obstacles,curr+1,lane);
        }
        int ans = INT_MAX;

        for(int newLane = 1;newLane<=3;newLane++){
            if(newLane!=lane && obstacles[curr]!=newLane){
                ans = min(ans,1+solve(obstacles,curr,newLane));
            }
        }
    return memo[curr][lane]=ans;   
    }
    int minSideJumps(vector<int>& obstacles) {
        n=obstacles.size()-1;
        memo.assign(n+1,vector<int>(4,INT_MIN));
        return solve(obstacles,0,2);
    }
};