class Solution {
public:
    string smallestString(string s) {
        int i = 0;
        int n = s.size();
        while(i<n && s[i]=='a')i++;
        if(i==n){
            s[n-1]='z';
            return s;}
        int start = i;
        while(i<n && s[i]!='a')i++;
        int end=i;

        //modify;

        for(int j=start;j<end;j++){
            s[j] = 'a'+(s[j]-'a'-1);
        }

        return s;
    }
};