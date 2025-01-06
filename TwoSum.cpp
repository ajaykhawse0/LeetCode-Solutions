//Brute Force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

for(int i=0;i<nums.size();i++){

    for(int j=i+1;j<nums.size();j++){

        if(nums[i]+nums[j]==target){
            return{i,j};
        }
    }}
    return{};

        }
};

//Optimal
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};
            }
            hash[nums[i]] = i;
        }
        // Return an empty vector if no solution is found
        return {};
    }
};
