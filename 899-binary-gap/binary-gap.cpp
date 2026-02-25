class Solution {
public:
    int binaryGap(int n) {
        bitset<32>binary(n);
        
        int prev=-1;
        int maxCount=0;
        
        for(int i=0;i<32;i++){
            
             if(binary[i]==1){
                if(prev!=-1){
                maxCount=max(maxCount,i-prev);
                }
                prev=i;
             }
             
        }
    return maxCount;}
};