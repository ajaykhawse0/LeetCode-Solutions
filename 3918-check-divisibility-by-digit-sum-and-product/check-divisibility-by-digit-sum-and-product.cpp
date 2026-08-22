class Solution {
public:
    long long sum = 0;
    long long product = 1;

    void solve(int n) {
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            sum += d;
            product = product * d;
        }
    }
    bool checkDivisibility(int n) {
        solve(n);
        return (n % (sum + product) == 0);
    }
};