class Solution {
public:
    typedef long long ll;
    typedef pair<long long, long long> P;
    string s;
    int n;
    vector<vector<vector<vector<vector<P>>>>> dp;

    P solve(ll idx, bool tight, int lastDigit, int secondLast,
            bool isLeadingZero) {
        if (idx >= n)
            return {1, 0};

        if (dp[idx][tight][isLeadingZero][lastDigit + 1][secondLast + 1] !=
            make_pair(-1LL, -1LL))
            return dp[idx][tight][isLeadingZero][lastDigit + 1][secondLast + 1];

        ll totalNumbers = 0;
        ll totalWaviness = 0;

        ll lb = 0;                                 // lower bound
        ll ub = (tight == 1) ? (s[idx] - '0') : 9; // upperbound

        for (ll digit = lb; digit <= ub; digit++) {
            bool newisLeadingZero = isLeadingZero && (digit == 0);

            int newSecondLast = lastDigit;
            int newlastDigit = newisLeadingZero ? -1 : digit;

            auto [remaintotalNumbers, remaintotalWaviness] =
                solve(idx + 1, (tight && digit == ub), newlastDigit,
                      newSecondLast, newisLeadingZero);

            if (!newisLeadingZero && lastDigit >= 0 && secondLast >= 0) {
                bool peak = (secondLast < lastDigit && lastDigit > digit);
                bool valley = (secondLast > lastDigit && lastDigit < digit);

                if (peak || valley) {
                    totalWaviness +=
                        remaintotalNumbers; // fter these all no. combos will
                                            // take part in waviness
                }
            }

            totalNumbers += remaintotalNumbers;
            totalWaviness += remaintotalWaviness;
        }
        return dp[idx][tight][isLeadingZero][lastDigit + 1][secondLast + 1] = make_pair(
                   totalNumbers, totalWaviness);

        // return {totalNumbers, totalWaviness};
    }
    ll fun(ll num) {
        if (num < 0)
            return 0; // no possibility from 0-99

        s = to_string(num);
        n = s.size();

        dp.assign(n, vector<vector<vector<vector<P>>>>(
                         2,

                         vector<vector<vector<P>>>(
                             2, vector<vector<P>>(11, vector<P>(11,

                                                                {-1, -1}))

                                 ))

        );

        auto [totalNumbers, totalWaviness] = solve(0, true, -1, -1, true);

        return totalWaviness;
    }
    long long totalWaviness(long long num1, long long num2) {
        return fun(num2) - fun(num1 - 1);
    }
};