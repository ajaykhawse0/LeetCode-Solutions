class Solution {
public:
long  MOD = 1e9+7;
    long  sieve(long  n ){
    long  cnt=0;
        vector<long >prime(n+1,true);
         for (long  p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            
            // marking as false
            for (long  i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }  

    for(long  i=2;i<=n;i++){
        if(prime[i])cnt++;
    }
    return cnt;
    }

    long  fact(long  n){
        if(n==0 || n==1)return 1;

        return (n*fact(n-1))%MOD;
    }
    long  numPrimeArrangements(long  n) {
        long  count = sieve(n);
        long  remaining  =  n-count;

        return ((fact(count)%MOD) * (fact(remaining)%MOD))%MOD;

    }
};