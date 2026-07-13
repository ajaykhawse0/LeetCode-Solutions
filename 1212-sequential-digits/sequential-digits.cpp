class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        set<int> st;
        for (int i = 0; i < 9; i++) {
            for (int len = 2; i + len <= 9; len++) {
                int num = stoi(s.substr(i, len));

                if (num >= low && num <= high) {
                    st.insert(num);
                }
                if (num > high) {
                    break;
                }
            }
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};