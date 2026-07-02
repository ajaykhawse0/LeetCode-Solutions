class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        int ones = 0;
        int zeros=0;
        for(char c:binary){
            if(c=='1')ones++;
            else zeros++;
        }
        if(zeros<2)return binary;
        int startingOnes = 0;
        for(char c:binary){
            if(c=='1')startingOnes++;
            else{
                break;
            }
        }

        ones -= startingOnes;
        string res = "";

        for(int i=0;i<startingOnes;i++){
               res += '1';
        }
        for(int i = 0;i<zeros-1;i++){
            res += '1';
        }
        if(zeros>1)res += '0';
       for(int i=0;i<ones;i++){
        res += '1';
       }
    return res;}
};