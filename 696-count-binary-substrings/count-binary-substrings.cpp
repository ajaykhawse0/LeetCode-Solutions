class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr=1,prev=0,cnt=0;
        int n = s.size();
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                curr++;
            }

            else{
           
                cnt+=min(curr,prev);
                prev=curr;
                curr=1;
            }

        }
        cnt+=min(curr,prev);
        return cnt;
    }
};
