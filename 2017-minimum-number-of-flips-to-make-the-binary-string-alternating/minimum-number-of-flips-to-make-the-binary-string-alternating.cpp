class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string str =
            s + s; // in str we can get all the possible string of length n that we can make using type1 transformation

        string expected1 = "";
        string expected2 = "";

        for (int i = 0; i < 2 * n; i++) {
            expected1 += (i % 2 == 0) ? '0' : '1';
            expected2 += (i % 2 == 0) ? '1' : '0';
        }

        int ans = 1e9;
        int flip1 = 0, flip2 = 0;

        // using sliding window
        int j = 0;
        int i = 0;

        while (j < 2*n) {
            if (expected1[j] != str[j])
                flip1++;
            if (expected2[j] != str[j])
                flip2++;

         // If window size exceeds n (invalid rotation length)
            // shrink window from left
            if (j - i + 1 > n) {

                // Remove contribution of leftmost element
                if (str[i] != expected1[i])
                    flip1--;

                if (str[i] != expected2[i])
                    flip2--;

                i++;
            }
            
            if(j-i+1==n){
                ans = min({ans,flip1,flip2});
            }
            j++;

        }

        return ans;
    }
};