class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int m = s.size();
        int mark = m; //digits to mark as 9

        for(int right = m-1;right>0;right--){
            if(s[right-1]>s[right]){
                //conditions voilated
                mark=right;
                s[right-1]--;//decrease the no. that causes issue by 1
            }
            for(int i = mark ;i<m;i++){
                s[i]='9';
            }
        }
    return stoi(s);}
};