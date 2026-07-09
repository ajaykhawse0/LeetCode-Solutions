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
    int strStr(string s, string pat) {
        int n = s.size();
        int m = pat.size();
        vector<int>LPS(m,0);
        buildLps(LPS,pat,m);
        // for(auto&L:LPS){
        //     cout<<L<<",";
        // }

        int i=0;
        int j=0;

        while(i<n){

            if(s[i]==pat[j]){
                i++;
                j++;

                if(j==m)return i-j;
            }
            else{
                if(j>0){
                    j = LPS[j-1];
                }
                else{
                    //j==0 
                    i++;
                }
            }
        }
        return -1;
    }
};