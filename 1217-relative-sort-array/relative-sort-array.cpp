class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        vector<int> freq(1001, 0);

        for (int x : arr1) {
            freq[x]++;
        }

        vector<int> ans;

        for (int x : arr2) {

            while (freq[x]--) {
                ans.push_back(x);
            }
        }

        for (int x = 0; x <= 1000; x++) {

            while (freq[x]-- > 0) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};