class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //line Sweep vertical
        map<int,int>line;

        for(auto & trip : trips){
            int passengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            line[from]+=passengers;
            line[to]-=passengers;

        }
        int sum = 0;
        for(auto &[location,pass]:line){
            sum+=pass;
            if(sum>capacity)return false;


        }
 return true;   }
};