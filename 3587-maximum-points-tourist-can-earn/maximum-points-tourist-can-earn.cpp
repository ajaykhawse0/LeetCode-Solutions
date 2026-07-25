class Solution {
public:vector<vector<int>>memo;
    int solve(int currCity,vector<vector<int>>& stayScore, vector<vector<int>>& travelScore,int day,int n){
        
        if(day<0)return  0;
        if(memo[day][currCity]!=INT_MIN)return memo[day][currCity];

        int stay = stayScore[day][currCity] + solve(currCity,stayScore,travelScore,day-1,n);

        int travel = 0;
        
        // all are interconnected
        for(int nextCity = 0;nextCity<n;nextCity++){
            if(nextCity==currCity)continue;

            travel = max(travel,travelScore[nextCity][currCity]+solve(nextCity,stayScore,travelScore,day-1,n));
        }

        return memo[day][currCity] = max(stay,travel);
    }
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
     int ans = INT_MIN;
     
     memo.assign(k,vector<int>(n,INT_MIN));
     for(int currCity=0;currCity<n;currCity++){
        ans = max(ans,solve(currCity,stayScore,travelScore,k-1,n));
     }
 
     return ans;   
    }
};