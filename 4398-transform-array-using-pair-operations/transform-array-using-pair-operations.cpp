class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        // a observation that i got from solutions tab that sum never changes

        return accumulate(source.begin(),source.end(),0LL) == accumulate(target.begin(),target.end(),0LL);
    }
};