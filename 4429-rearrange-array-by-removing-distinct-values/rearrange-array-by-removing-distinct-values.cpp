class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>freq(101,0);

        for(int a:nums){
            freq[a]++;
        }
        int n = nums.size();

        vector<int>ans;
        while(n--){
            bool allZero = true;
            for(int i=0;i<101;i++){
                if(freq[i]!=0){
                    allZero = false;
                    ans.push_back(i);
                    freq[i]--;
                }
            }
            if(allZero)return ans;
        }
 return ans;   }
};