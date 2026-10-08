class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int res = 0;
        
        for(int b:batteryPercentages){
            if(b-res>0)res++;
        }
    return res;}
};