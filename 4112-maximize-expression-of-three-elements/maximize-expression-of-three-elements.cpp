class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int a = -101;
        int b = -101;
        int c = 101;

        for(int n:nums){
            if(n>a){
                b=a;
                a=n;
            }
            else{
                b=max(b,n);
            }
                c=min(c,n);
      cout<<a<<","<<b<<","<<c<<endl;
      
        }
    
    return a+b-c;}
};