// 6. Zigzag Conversion

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();

        if(n==0||n==1||numRows==1)return s;
           vector<vector<char>>rows(numRows);
        int idx=0,d=1;

        for(char c:s){
            rows[idx].push_back(c);
            if(idx==0){
                d=1;
            }
            else if(idx==numRows - 1){
                d=-1;
            }
            idx+=d;
        }
string result;
        for(auto &row:rows){
            for(char c :row){
                result+=c;
            }
        }
    return result;}
};

// T.C=>O(n)
// S.C=>O(n)
