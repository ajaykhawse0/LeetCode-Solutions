class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp = a;
       int ans  = 1;
        while(temp.size()<b.size()){
            temp += a;
            ans++;
        }

        if(temp.find(b)!=string::npos)return ans;

        temp += a;
        ans++;
        if(temp.find(b)!=string::npos)return ans;


return -1;

    }
};