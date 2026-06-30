class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int>freq;

        //sliding window approach
        int r = 0;
        int l = 0;
     // int n = fruits.size();
        int ans  = 0;
        while(r  < n){
            freq[fruits[r]]++;

            while(freq.size()>2 && l<n){
                freq[fruits[l]]--;
                if(freq[fruits[l]]==0){
                    freq.erase(fruits[l]);
                }
                l++;
            }

            ans = max(ans,r-l+1);

            r++;
        }
 return ans;   }
};