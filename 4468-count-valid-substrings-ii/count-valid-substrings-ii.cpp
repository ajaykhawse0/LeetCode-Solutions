class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();

        vector<int> nextA(n + 1);
        vector<int> nextB(n + 1);
        vector<int> nextC(n + 1);

        nextA[n] = n;
        nextB[n] = n;
        nextC[n] = n;

        for (int i = n - 1; i >= 0; i--) {
            nextA[i] = (s[i] == 'a') ? i : nextA[i + 1];
            nextB[i] = (s[i] == 'b') ? i : nextB[i + 1];
            nextC[i] = (s[i] == 'c') ? i : nextC[i + 1];
        }

        long long totalSubStr = (long long)n * (n + 1) / 2;

        long long invalidSub = 0;

        for (int i = 0; i < n; i++) {
            int A = nextA[i];
            if (A == n)
                continue;
            int B = nextB[A+1];
            if (B == n)
                continue;
            int C = nextC[B+1];
            if (C == n)
                continue;

            invalidSub += n - C; // because everything thing in these substr
                                 // depends on nextPos of C;
        }

        return totalSubStr - invalidSub;
    }
};