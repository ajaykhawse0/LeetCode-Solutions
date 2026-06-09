class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int num:nums){
            mpp[num]++;
        }
        int maxSeqLen =0 ;
        for(auto[num,freq]:mpp){
            if(mpp.count(num)){
                int prev = num-1;
                if(!mpp.count(prev)){
                    int next = num+1;
                    int len=1;
                    while(mpp.count(next)){
                        len++;
                        next++;
                    }
                    maxSeqLen = max(maxSeqLen,len);
                }
            }
        }
return maxSeqLen;
    }
};