class Solution {
public:
    bool judgeCircle(string moves) {
        int cntU=0,cntD=0,cntL=0,cntR=0;

        for(char c : moves){
            if(c=='U')cntU++;
           else if(c=='D')cntD++;
           else if(c=='L')cntL++;
            else cntR++;
        }
        if((cntU==cntD) && (cntL==cntR))return true;
        return false;
    }
};