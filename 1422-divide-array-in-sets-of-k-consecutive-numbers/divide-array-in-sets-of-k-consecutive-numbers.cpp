class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
         if (nums.size() % k != 0) return false;
        map<int,int>mpp;
        for(int n:nums){
            mpp[n]++;
         }

      while(!mpp.empty()){
            
            int val = mpp.begin()->first;
            int freq = mpp.begin()->second;

            for(int i=val;i<val+k;i++){
                if(!mpp.count(i))return false;

                mpp[i]--;
                if(mpp[i]==0){
                    mpp.erase(i);
                }
            }
        }
        
        return true;
    }
};