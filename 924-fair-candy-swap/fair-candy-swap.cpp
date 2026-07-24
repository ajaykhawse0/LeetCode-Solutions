class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        long long sumA = accumulate(aliceSizes.begin(),aliceSizes.end(),0LL);
        long long sumB = accumulate(bobSizes.begin(),bobSizes.end(),0LL);
        
        unordered_set<int>setB(bobSizes.begin(),bobSizes.end());
         
        int diff = (sumB-sumA)/2; 

        for(int a:aliceSizes){
            if(setB.count(a+diff)){
                return {{a,a+diff}};
            }
        }

    return {{}};}
};