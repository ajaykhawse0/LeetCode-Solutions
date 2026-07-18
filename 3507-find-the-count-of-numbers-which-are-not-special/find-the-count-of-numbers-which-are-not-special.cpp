
class Solution {
public:
    vector<bool> sieve(int n) {
        vector<bool> prime(n + 1, true);

        prime[0] = prime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    prime[j] = false;
            }
        }

        return prime;
    }

    int nonSpecialCount(int l, int r) {
       int  limit  = sqrt(r);
        auto prime = sieve(limit);

        int special = 0;

        for (int num = 2; num <= limit; num++) {
            if(prime[num]){
                int x = num*num;

                if(x>=l && x<=r)special++;
            }
        }

        return (r - l + 1) - special;
    }
};