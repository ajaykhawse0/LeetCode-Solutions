class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>arr;
        for(int&n:nums){
            string s = to_string(n);
            for(char c : s){
                arr.push_back(c-'0');
            }
        }
    return arr;}
};