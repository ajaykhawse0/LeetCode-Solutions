class Solution {
public:
    string convert(int a) {
        string s;

        while (a > 0) {
            s += char('0' + (a & 1));
            a >>= 1;
        }

        reverse(s.begin(), s.end());

        return s;
    }
    int decimal(string s) {
        int n = s.size();

        int res = 0;

        for (char c : s) {
            if (c == '1') {
                res += pow(2, n-1);
            }
            n--;
        }
        return res;
    }
    int maxGoodNumber(vector<int>& nums) {

        string a = convert(nums[0]);
        string b = convert(nums[1]);
        string c = convert(nums[2]);

        return max({decimal(a + b + c), decimal(a + c + b), decimal(b + a + c),
                    decimal(b + c + a), decimal(c + a + b),
                    decimal(c + b + a)});
    }
};