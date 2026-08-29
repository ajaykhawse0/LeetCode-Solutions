class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int l1=s1.length();
        int l2=s2.length();
        int l3=s3.length();

        int n = min({l1,l2,l3});
        int equal = 0;
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i] && s2[i]==s3[i]){
                equal++;
            }
            else break;
        }
        if(equal==0)return -1;

        int ans = 0;
        ans += l1-equal;
        ans += l2-equal;
        ans += l3-equal;

        return ans;
    }
};