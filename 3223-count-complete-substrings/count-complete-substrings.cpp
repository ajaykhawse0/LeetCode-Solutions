class Solution {
public:
    using ll = long long;
    int countCompleteSubstrings(string word, int k) {
     int ans = 0;

        string temp = "";

        int n = word.length();

        for (int i = 0; i < n; i++) {
            temp += word[i];

            if (i <= n - 2) {
                if (abs(word[i + 1] - word[i]) > 2) {
                    ans += solve(temp, k);
                    temp = "";
                }
            }
        }
        ans += solve(temp, k);

        return ans;
    }

    ll solve(string s, int k) {
        // possible valid lens are k*1,k*2------k*26
        int n = s.size();
        int count = 0;
        for (int j = 1; j <= 26; j++) {
            int currLen = k * j;
            if (currLen > n)
                break;
            vector<int> freq(26, 0);
            // check all substr of length currLen
            for (int i = 0; i < currLen; i++) {
                freq[s[i] - 'a']++;
            }
            if (check(freq, j, k))
                count++;

            for (int i = currLen; i < n; i++) {
                freq[s[i - currLen] - 'a']--;
                freq[s[i] - 'a']++;
                if (check(freq, j, k))
                    count++;
            }
        }

        return count;
    }

    bool check(vector<int>&freq,int  charLimit,int k){
        int cnt = 0;
        for(int i=0;i<26;i++){
            if(freq[i]==0)continue;
            if(freq[i]!=k)return false;
            cnt++;
            if(cnt>charLimit)return false;
        }
        return true;
    }
};