
class Solution {
public:
    bool possible(string& temp, string& p) {
        int n = temp.size();
        int m = p.size();

        int i = 0, j = 0;

        while (i < n && j < m) {
            if (temp[i] != '+' && temp[i] == p[j])
                j++;
            i++;
        }

        return j == m;
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0;
        int r = removable.size();
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            string temp = s;

            for (int i = 0; i < mid; i++)
                temp[removable[i]] = '+';

            if (possible(temp, p)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};
