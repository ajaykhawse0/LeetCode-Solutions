class Solution {
public:
    int minInsertions(string s) {
        int openBrac = 0;
        int ans = 0;
        int n = s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='(')openBrac++;

            else{
                //step1:Check if we have consecutive )
                if(i+1<n && s[i+1]==')')i++;
                else ans++;

                //step2:if we already have encountered its corresponding ( before remove it else add it
                if(openBrac>0)openBrac--;
                else ans++;
            }

        }
        //if you can remaining open brackets add 2 ( for all of them

        ans += openBrac*2;

        return ans;
    }
};