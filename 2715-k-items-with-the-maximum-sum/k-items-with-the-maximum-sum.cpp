class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans  = 0; 
        while(k>0){
            if(numOnes>0){
                ans += min(numOnes,k);
                k-=numOnes;
                numOnes = 0;
            }
            else if(numZeros>0){
                
                k-=numZeros;
                numZeros = 0;
            }
            else{
                ans -= min(numNegOnes,k);
                k-=numNegOnes;
                numNegOnes = 0;
            }

        }
        
    return ans;}
};