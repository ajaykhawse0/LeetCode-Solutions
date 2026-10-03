class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(),sides.end());
        int a = sides[0];
        int b = sides[1];
        int c = sides[2];
        if (a + b <= c)
            return {};

        double A = acos((double)(b * b + c * c - a * a) / (2 * b * c));
        double B = acos((double)(a * a + c * c - b * b) / (2 * a * c));
        double C = acos((double)(a * a + b * b - c * c) / (2 * a * b));

        A = A * 180.0 / M_PI;
        B = B * 180.0 / M_PI;
        C = C * 180.0 / M_PI;

        vector<double>ans = {A,B,C};

        sort(ans.begin(),ans.end());

        return ans;
    }
};