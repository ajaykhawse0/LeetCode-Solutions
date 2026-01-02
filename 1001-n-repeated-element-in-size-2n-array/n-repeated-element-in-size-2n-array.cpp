class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;

        unordered_map<int,int>mpp;
        for(int &num : nums){
            mpp[num]++;
            
            if(mpp[num]==n)return num;
        }
return -1;    }
};