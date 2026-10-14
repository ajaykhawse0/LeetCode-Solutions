class Solution {
public:

    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num ||sum<0)return "";
        string result="";
        for(int i=0;i<num;i++){
            int d  = min(9,sum);
            result+=to_string(d);
            sum-=d;
        }
    return result;}
};