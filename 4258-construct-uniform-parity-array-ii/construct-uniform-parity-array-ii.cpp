class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       int mn = nums1[0];
       int oddCnt = 0;
        
        for(int i:nums1){
            mn = min(mn,i);
            if(i&1)oddCnt++;
        }

        if(mn&1)return true;

        return oddCnt == 0; 
    }
};