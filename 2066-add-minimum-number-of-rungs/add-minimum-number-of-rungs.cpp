class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int n = rungs.size();

        int cnt = 0;
        int prev = 0;
        for(auto rung:rungs){
             
             cnt += (rung-prev-1)/dist;

            prev = rung;
        }
 return cnt;   }
};