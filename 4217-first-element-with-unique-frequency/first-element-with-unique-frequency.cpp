class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>freq;
        unordered_map<int,int>freqCount;

        int n = nums.size();

        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(auto&it:freq){
            freqCount[it.second]++;
        }

          for(int i=0;i<n;i++){
            int f = freq[nums[i]];
            int cnt = freqCount[f];
            if(cnt==1)return nums[i];
        }
    return -1;}
};