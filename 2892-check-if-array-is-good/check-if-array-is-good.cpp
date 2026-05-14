class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        if(n!=maxEle+1)return false;
        unordered_map<int,int>mpp;
        int maxEleCnt=0;
        for(auto&i:nums){
            mpp[i]++;
            if(i==maxEle)maxEleCnt++;
        }
      
        for(int i=1;i<n;i++){
               if (!mpp.contains(i)) return false;        
        }
          
        
      return maxEleCnt==2?true:false;  
    }
};