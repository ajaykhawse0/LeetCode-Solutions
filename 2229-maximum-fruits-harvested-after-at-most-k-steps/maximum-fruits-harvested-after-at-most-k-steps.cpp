class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        unordered_map<int,int> mpp; // idx -> amount

        for(auto& f : fruits){
            mpp[f[0]] = f[1];
        }
        
        if (k == 0) return mpp[startPos];
        
        vector<int> left(k, 0);
        vector<int> right(k, 0);
        
        // --- Populate Left Array ---
        left[0] = mpp.count(startPos-1) ? mpp[startPos-1] : 0;
        int i = startPos - 2;
        int j = 1;
        while(i >= 0 && j < k){
            left[j] = (mpp.count(i) ? mpp[i] : 0) + left[j-1];
            i--;
            j++;
        }
        // FIX: Propagate the accumulated sum for the remaining steps 
        while(j < k) {
            left[j] = left[j-1];
            j++;
        }
        
        // --- Populate Right Array ---
        right[0] = mpp.count(startPos+1) ? mpp[startPos+1] : 0;
        i = startPos + 2;
        j = 1;
        while(i < startPos + k + 1 && j < k){
            right[j] = (mpp.count(i) ? mpp[i] : 0) + right[j-1];
            i++;
            j++;
        }
        // Propagate for right as well, just for consistency
        while(j < k) {
            right[j] = right[j-1];
            j++;
        }
        
        int ans = mpp[startPos];
        
        // --- Calculate Max moving Right then Left ---
        for(int step = 1; step <= k; step++){
            int temp = right[step-1] + mpp[startPos] + ((k - (2*step) - 1 >= 0) ? left[k - (2*step) - 1] : 0);
            ans = max(ans, temp);          
        }

        // --- Calculate Max moving Left then Right ---
        for(int step = 1; step <= k; step++){
            int temp = left[step-1] + mpp[startPos] + ((k - (2*step) - 1 >= 0) ? right[k - (2*step) - 1] : 0);
            ans = max(ans, temp);            
        }
        
        return ans;
    }
};