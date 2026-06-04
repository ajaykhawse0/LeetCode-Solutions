class Solution {
public:
    int clumsy(int n) {
        vector<int> v;
        v.push_back(n);

        int op = 0;

        for (int i = n - 1; i >= 1; --i) {
            if (op == 0) {
                v.back() *= i;
            }
            else if (op == 1) {
                v.back() /= i;
            }
            else if (op == 2) {
                v.push_back(i);
            }
            else {
                v.push_back(-i);
            }

            op = (op + 1) % 4;
        }

        int ans = 0;
        for (int x : v) ans += x;

        return ans;
    }
};