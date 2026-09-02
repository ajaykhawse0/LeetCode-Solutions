class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=0;
        int even=0;
        for(int&x:nums1){
            if(x%2==0)even++;
            else odd++;
        }
        int n = nums1.size();

        if(even==n || odd==n)return true;

        if(odd>=2)return true;//all even is possiible

        if(odd>=1 && even>=1) return true; // all odd is possible

        return false;
    }
};