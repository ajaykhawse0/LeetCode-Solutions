class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int>ans(n);
        int open =0;
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                ans[i]=open&1;
                open++;
            }
            else{
                open--;
                ans[i]=open&1;
            }

        }
return ans;    }
};