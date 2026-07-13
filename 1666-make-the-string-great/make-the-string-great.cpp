class Solution {
public:
    string makeGood(string s) {
        // diff betn lowercase and uppercase is 32 in ascii it will help us

        string ans = "";

        for (char c : s) {
            if (!ans.empty() && abs(ans.back()-c) == 32) {
               ans.pop_back();

            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};