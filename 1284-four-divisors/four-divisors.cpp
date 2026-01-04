class Solution {
public:
      int solve(int n){
        int cnt=0,sum=0;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
               
                //means both value are same then put only one
                if(n/i==i){
                    sum+=i; 
                    cnt++;
                }
                else{
                    sum=sum+n/i;
                    sum+=i;
                    cnt+=2;
                }
            }
        }
      if(cnt==4)return sum;
      return 0;}
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int&n:nums){
            ans+=solve(n);
        }
    return ans;}
};