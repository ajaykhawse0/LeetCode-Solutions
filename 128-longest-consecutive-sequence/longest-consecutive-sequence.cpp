class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool>mpp;
        for(int &num:nums){
            mpp[num]=true;
        }
        int maxLen=0;
        
        for(auto&it:mpp){
            int num = it.first;
           int prev=num-1;
       
       //only start when the current num is start of a sequence
        if(!mpp.count(prev)){
            int next=num+1;
             int len = 1;
          
            while(mpp.count(next) ){
                next++;
                len++;

            }
            maxLen = max(maxLen,len);
        }}
    return maxLen;}
};