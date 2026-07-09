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
    bool rotateString(string s, string pat) {
        if(s.length()!=pat.length())return false;
         s = s+s;
        
        int n = s.size();
        int m = pat.size();
        vector<int>LPS(m,0);
        buildLps(LPS,pat,m);
     

        int i=0;
        int j=0;

        while(i<n){

            if(s[i]==pat[j]){
                i++;
                j++;

                if(j==m){return true;}
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
        return false;
    }
       
 
        
    
};
