class Solution {
public:
    int minOperations(string s) {
        string s1="",s2="";
        int n = s.size();
        for(int i=0;i<n;i++){
            if(i&1){
                s1+='1';
                s2+='0';
            }
            else{
                s1+='0';
                s2+='1';
            }

        }
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s[i])cnt1++;
            if(s2[i]!=s[i])cnt2++;
        }
    return (cnt1<cnt2)?cnt1:cnt2;}
};