class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0=0;
        int cnt1=0;
        int cnt2=0;

        for(int stone:stones){
            int val = stone%3;
            if(val==0)cnt0++;
            else if(val==1)cnt1++;
            else cnt2++;


            
        }
        if(cnt0%2==0){
            return(cnt1>0 && cnt2>0);
        }
        return abs(cnt1-cnt2)>2;
    }
};