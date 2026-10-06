class Type {
    public:
    int digSum, idx, value;
    Type(int d, int i, int v) {
        digSum = d;
        idx = i;
        value = v;
    }
};
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<Type> arr;

        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({digSUM(nums[i]), i, nums[i]});
        }

        sort(arr.begin(), arr.end(),
             [&](const Type& a, const Type& b) {
                 if (a.digSum == b.digSum) {
                     return a.value < b.value;
                 }
                 return a.digSum < b.digSum;
             });

        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            while (arr[i].idx != i) {
                swap(arr[i], arr[arr[i].idx]);
                ans++;
            }
        }
        return ans;
    }
    int digSUM(int d) {
        int s = 0;
        while (d > 0) {
            s += d % 10;
            d /= 10;
        }

        return s;
    }
};