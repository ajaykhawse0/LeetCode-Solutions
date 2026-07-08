class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefSum(n, 0);
        vector<int> pos;
        vector<int> digits;

        if (s[0] != '0') {
            pos.push_back(0);
            digits.push_back(s[0] - '0');
            prefSum[0] = s[0] - '0';
        }

        for (int i = 1; i < n; i++) {
            if (s[i] != '0') {

                pos.push_back(i);
                digits.push_back(s[i] - '0');
                
            }
            prefSum[i] = prefSum[i - 1] + (s[i] - '0');
        }
        int m = digits.size();
        // precompute power10 for each digit;
        vector<long long> power10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        // precompute all the numbers from digit
        vector<long long> prefNum(m);
        if (m > 0) {
            prefNum[0] = digits[0];

            for (int i = 1; i < m; i++) {
                prefNum[i] = (prefNum[i - 1] * 10 + digits[i]) % MOD;
                //<<prefNum[i]<<endl;
            }
        }
        //<<"query: "<<endl;

        vector<int> ans;

        for(auto&q:queries){
            int l = q[0],r = q[1];

            long long sum = (prefSum[r] - (l!=0 ? prefSum[l-1]:0))%MOD;

            auto itL = lower_bound(pos.begin(),pos.end(),l);
            auto itR = upper_bound(pos.begin(),pos.end(),r);
            
            if(itL==itR){
                ans.push_back(0);
                continue;
            }

            int L =  itL - pos.begin();
            int R =  (itR - pos.begin())-1;
            //<<"Index :";
            //<<L<<","<<R<<endl;
            int len = R-L+1;
            long long num = prefNum[R];
            if(L>0){
              num = (num - ((prefNum[L-1] * power10[len])%MOD) + MOD ) %MOD; 
            }

            ans.push_back((num*sum)%MOD);

            //<<num<<endl;
            
        }

        // for (auto& q : queries) {
        //     if (q[0] != 0) {
        //         q[0]--;

        //         string t = mpp[q[1]].substr(mpp[q[0]].size());
        //         if (!t.empty()) {
        //             long long num = stoll(t);
        //             long long mul = prefSum[q[1]] - prefSum[q[0]];

        //             long long value = (num * mul) % MOD;
        //             ans.push_back(value);
        //         }
        //          else{
        //             ans.push_back(0);
        //         }

        //     } else {

        //         string t = mpp[q[1]];
        //         if (!t.empty()) {
        //             long long num = stoll(t);
        //             long long mul = prefSum[q[1]];

        //             long long value = (num * mul) % MOD;
        //             ans.push_back(value);
        //         }
        //         else{
        //             ans.push_back(0);
        //         }
        //     }
        // }

        return ans;
    }
};