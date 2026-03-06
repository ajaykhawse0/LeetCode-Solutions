class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //1st Approach
        int n = nums.size();
        k%=n;
        // vector<int>temp(n);
        // for(int i=0;i<k;i++){
        //     temp[i]=nums[n-k+i];

        // }
        // for(int i=0;i<n-k;i++){
        //     temp[i+k]=nums[i];
        // }
        // nums=temp;
        
        //2nd approach

        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        
        // 3rd Approach

        

            }
};

