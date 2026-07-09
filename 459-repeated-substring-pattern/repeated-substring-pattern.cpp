class Solution {
public:
void buildLps(vector<int>&LPS,string &pat,int m){
        int prev = 0;
        int curr = 1;

        while(curr<m){
            
            //best case
            if(pat[curr]==pat[prev]){
                prev++;
                LPS[curr] = prev;
                curr++;
            }
            else{
                if(prev!=0){
                    prev = LPS[prev-1];
                }
                else{
                    LPS[curr] = 0;//no need to mark as it is already marked
                    curr++;
                }
            }
        }

    }
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int>LPS(n,0);
        buildLps(LPS,s,n);
        
        int len = LPS[n-1];
        int period = n-len;
        if((n%period == 0) && (n/period) > 1)return true;

        return false;
    }
};