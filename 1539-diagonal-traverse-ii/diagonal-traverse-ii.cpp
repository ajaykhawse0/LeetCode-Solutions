class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = 0;

        // find max col size

        for (int i = 0; i < m; i++) {
            n = max(n, (int)nums[i].size());
        }

        vector<vector<int>> temp(m + n);
        // insert the val in temp creating an adj list
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < nums[i].size(); j++) {

                temp[i + j].push_back(nums[i][j]);
            }
        }

        // all the vals in temp are in reversed order resolve it

        for (int i = 0; i < m + n; i++) {
            reverse(temp[i].begin(), temp[i].end());
        }

        // copy answer to ans;
        vector<int> ans;

        for (int i = 0; i < m+n; i++) {
            for (int j = 0; j < temp[i].size(); j++) {

                ans.push_back(temp[i][j]);
            }
        }
        return ans;
    }
};