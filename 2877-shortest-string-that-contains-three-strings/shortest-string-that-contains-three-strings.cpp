class Solution {
public:
string merge(string a, string b) {
    if (a.find(b) != string::npos) return a;

    int m = min(a.size(), b.size());

    for (int k = m; k >= 0; k--) {
        if (a.substr(a.size() - k) == b.substr(0, k))
            return a + b.substr(k);
    }

    return a + b;
}
    string minimumString(string a, string b, string c) {
        vector<string>ans = {
         merge(merge(a,b),c),
         merge(merge(a,c),b),
         merge(merge(b,a),c),
         merge(merge(b,c),a),
         merge(merge(c,a),b),
         merge(merge(c,b),a)
        };

        string res = ans[0];


       for (int i = 1; i <  6;i++) {
            if (ans[i].size() < res.size() ||
               (ans[i].size() == res.size() && ans[i] < res)) {
                res = ans[i];
            }
        }
    return res;}
};