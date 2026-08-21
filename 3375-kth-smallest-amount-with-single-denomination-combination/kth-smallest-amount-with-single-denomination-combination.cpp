class Solution {
public://copied (Will study this later only for streak)
    long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
    long long cnt(long long x,vector<int>& c){
        long long ans=0;
        int n=c.size();
        for(int m=1;m<(1<<n);m++){
            long long l=1;
            int bits=0;
            for(int i=0;i<n;i++) if(m>>i&1){
                bits++;
                long long g=gcd(l,c[i]);
                l=l/g*c[i];
                if(l>x){l=0;break;}
            }
            if(l)
                ans += (bits&1 ? 1 : -1)*(x/l);
        }
        return ans;
    }
    long long findKthSmallest(vector<int>& c,int k){
        long long l=1,r=1LL*(*min_element(c.begin(),c.end()))*k;
        while(l<r){
            long long m=(l+r)/2;
            if(cnt(m,c)>=k) r=m;
            else l=m+1;
        }
        return l;
    }
};