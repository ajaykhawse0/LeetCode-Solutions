class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            st.insert(A[i]);
            int cnt = 0;
            for(int j=0;j<=i;j++){
               if(st.count(B[j])){
                cnt++;
               }
            }
            ans[i]=cnt;
        }
    return ans;}
};