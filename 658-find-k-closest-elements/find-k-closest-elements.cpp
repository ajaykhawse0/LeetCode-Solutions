class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - 1;
        int len = arr.size();

        while (len > k) {
            if (abs(arr[l] - x) < abs(arr[r] - x)) {
                r--;
                len--;
            } else if (abs(arr[l] - x) > abs(arr[r] - x)) {
                l++;
                len--;
            } else if (abs(arr[l] - x) == abs(arr[r] - x)) {
                if (arr[l] <= arr[r]) {
                    r--;
                    len--;
                } else if (arr[l] > arr[r]) {
                    l++;
                    len--;
                }
            }
        }

        vector<int> ans(arr.begin() + l, arr.begin() + r + 1);

        return ans;
    }
};