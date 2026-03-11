class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int len = log2(n) + 1;
        string bin = bitset<32>(n).to_string().substr(32-len,32);
        int l = bin.length();
        int num=0;
        for(int  i=l-1,idx=0;i>=0;i--,idx++){
         if(bin[i]=='0')num+=pow(2,idx);
        }

return num;}
    // return 0;}
};