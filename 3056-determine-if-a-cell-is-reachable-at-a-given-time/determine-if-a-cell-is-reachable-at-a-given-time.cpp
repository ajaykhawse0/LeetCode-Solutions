class Solution {
public:
        // vector<vector<int>>canMove = {{0,1},{1,0},(1,1)};//down,left,diagonal
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xdiff =  abs(sx-fx);
        int ydiff =  abs(fy-sy);

        if(xdiff == 0 && ydiff == 0 && t == 1)return false;

        return max(xdiff,ydiff)<=t;
        
              
    }
};