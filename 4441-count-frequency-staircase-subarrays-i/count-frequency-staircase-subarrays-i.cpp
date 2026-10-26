class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            vector<int>freq;
            unordered_map<int,int>posMap;

            for(int j=i;j<n;j++){
                if(!posMap.count(nums[j])){
                    posMap[nums[j]] = freq.size();
                    freq.push_back(1);
                }
                else freq[posMap[nums[j]]]++;
                

                bool valid = true;

                for(int k=0;k<freq.size();k++){
                    if(freq[k]!=k+1){
                        valid = false;
                        break;
                    }
                }

                if(valid)ans++;
            }
        }
    return ans;}
};