class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = INT_MIN;
        int Smx = INT_MIN;

        for(int &num : nums){
            if(num>mx){
                Smx = mx;
                mx = num;
            }
            else if(num>Smx){
                Smx = num;
            }
        }
    return (mx-1)*(Smx-1); }
};