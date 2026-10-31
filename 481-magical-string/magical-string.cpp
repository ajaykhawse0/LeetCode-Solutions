class Solution {
public:
    int magicalString(int n) {
        if(n<=0)return 0;
        if(n<=3)return 1;

        string s = "122";//base

        int i = 2;
        int num = 1;

        while(s.size()<n){
            int freq = s[i] - '0';

            for(int j=0;j<freq;j++){
                s += (num+'0');
            }

            num = 3-num;//toggle
            i++;
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            if(s[i]=='1')ans++;
        }
 return ans;   }
};