class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
     vector<int>nums = arr;
     sort(nums.begin(),nums.end());
    int rank = 1;
    unordered_map<int,int>mpp;
     for(int num:nums){
        if(!mpp.count(num)){
            mpp[num] = rank++;
        }
     }   
    
    for(int &n:arr){
        n = mpp[n];
    }
return arr;
    }
};