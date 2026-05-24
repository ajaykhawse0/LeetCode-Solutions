class Solution {
public:
vector<int>dp,nums;
int n;

     int solve(int currIdx , int d){
        if(currIdx>=n)return 0;

        if(dp[currIdx]!=0)return dp[currIdx];

        int jumps = 1;
        bool increase=true,decrease=true;
        
        for(int x=1;x<=d;x++){
        if(!increase && !decrease)break;
        //1st condition 
        if(increase){
        if((currIdx+x)<n && nums[currIdx]>nums[currIdx+x] ){
           jumps = max(jumps,1+solve(currIdx+x,d));
        }
        else increase=false;
        }
         //2nd condition
        if(decrease){
             if((currIdx-x)>=0 && nums[currIdx]>nums[currIdx-x] ){
           jumps = max(jumps,1+solve(currIdx-x,d));
        }
        else decrease=false;
        
        }

        }

        // for(int x=1;x<=d;x++){
        // //2st condition 
        // if((currIdx-x)>=0 && nums[currIdx]>nums[currIdx-x] ){
        //    jumps = max(jumps,1+solve(currIdx-x,d));
        // }
        // else break;
        // }
        return dp[currIdx] = jumps;
     }
    int maxJumps(vector<int>& arr, int d) {
      n=arr.size();
      nums=arr;
      dp.assign(n,0);
      int ans =0 ;
      for(int i=0;i<n;i++){
       ans = max(ans,solve(i,d));
    
      }  
      return ans;
    }
};