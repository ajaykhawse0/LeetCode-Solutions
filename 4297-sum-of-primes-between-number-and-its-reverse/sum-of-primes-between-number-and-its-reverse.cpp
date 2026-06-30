class Solution {
public:
int sieve(int mn,int mx){
    vector<bool>prime(mx+1,true);
    prime[0]=false;
    prime[1]=false;
    for(int p=2;p*p<=mx;p++){

        if(prime[p]){

            for(int i=p*p;i<=mx;i+=p){
                prime[i]=false;
            }
        }
    }
    int sum=0;
    for(int i=mn;i<=mx;i++){
       sum += (prime[i]?i:0);
    }
    return sum;
}
    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        reverse(s.begin(),s.end());
        int r = stoi(s);
        int mx = max(n,r);
        int mn = min(n,r);
        
        return sieve(mn,mx);
    }
};