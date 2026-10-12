class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>ans;
        int place = 1;
        string s = to_string(n);

        for(int i=1;i<s.size();i++){
            place *= 10;

        }

        for(char c:s){
            int d = c-'0';
            if(d){
                ans.push_back(d*place);
            }
            place /= 10;
        }
    return ans;}
};