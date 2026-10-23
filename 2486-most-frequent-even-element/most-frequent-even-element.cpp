class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>freq;
      

        for(int n:nums){
            if(n%2==0){
               
                freq[n]++;
            }
        }
        int ans = -1;
        int mF = 0;
        
        for(auto [num,f]:freq){
            
            if(f>mF){
                mF=f;
                ans = num;
            }
        }
        
  return ans;  }
};