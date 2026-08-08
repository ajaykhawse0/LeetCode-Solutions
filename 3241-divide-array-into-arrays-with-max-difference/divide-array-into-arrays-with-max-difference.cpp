class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        ;
        vector<vector<int>>ans;

        for(int i=0;i+2<n;i+=3){
            if(nums[i+2]-nums[i]>k)return {};
            vector<int>temp;
            for(int j=i;j<i+3;j++){
              temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
 return ans;   }
};