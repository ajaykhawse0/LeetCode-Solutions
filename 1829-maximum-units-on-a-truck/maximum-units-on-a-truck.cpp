class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[&](const vector<int>&a,const vector<int>&b){
            return a[1]>b[1];
        });
        int ans = 0;
         for(auto&box:boxTypes){
            if(truckSize>=box[0]){
                ans += (box[0]*box[1]);
                truckSize-=box[0];
            }
            else{
                ans +=  truckSize*box[1];
                truckSize = 0;
            }
            if(truckSize == 0)break;
         }
        return ans;
    }
};