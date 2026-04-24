class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cntSpace =0;
        int cntLeft =0;
        int cntRight =0;

        for(char c:moves){
            if(c=='L'){
                cntLeft++;
            }
            else if(c=='R'){
                cntRight++;
            }
            else{
                cntSpace++;
            }
        }
        if(cntLeft==0 && cntRight==0)return cntSpace;
        return (cntLeft<cntRight)?(cntRight+cntSpace-cntLeft):(cntLeft+cntSpace-cntRight);
    }
};