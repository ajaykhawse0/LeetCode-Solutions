class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int ans = INT_MAX;
        int maxmins = targetSeconds/60;

        for(int mins = 0;mins<=maxmins;mins++){
            int secs = targetSeconds - (mins*60);

            if(secs>99 || mins>99)continue;

           ans = min(ans,helper(mins,secs,startAt,moveCost,pushCost,targetSeconds));
        }
   return ans; }
    int helper(int mins,int secs,int startAt, int moveCost, int pushCost, int targetSeconds){
             int cost  = 0;

             string s = to_string(100*mins+secs);

             char curr = (char)(startAt+'0');

             for(char c:s){
                if(curr==c){
                    cost += pushCost;
                }
                else{
                    curr = c;
                    cost += moveCost;
                    cost += pushCost;
                }
             }
   return cost; }
};