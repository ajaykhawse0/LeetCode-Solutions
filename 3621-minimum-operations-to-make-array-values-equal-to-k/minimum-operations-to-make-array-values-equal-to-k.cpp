class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
      int mn = *min_element(nums.begin(),nums.end());

      if(mn<k)return -1;

      bitset<100001>st;

      for(int n:nums){
        if(n>k)st.set(n);
      }

      return st.count();
     

    }
};