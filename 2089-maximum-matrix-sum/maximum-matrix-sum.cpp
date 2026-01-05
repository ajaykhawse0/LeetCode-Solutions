class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long minAbs = INT_MAX;
        long long totalSum =0;
        long long negatives =0;

        for(auto&row:matrix){
            for(auto&val:row){
                if(val<0)negatives++;

                long long absVal = abs(val);
                totalSum+=absVal;
                minAbs = min(minAbs,absVal);
            }
        }
 return negatives%2==0 ? totalSum : totalSum - 2LL*minAbs;   }
};