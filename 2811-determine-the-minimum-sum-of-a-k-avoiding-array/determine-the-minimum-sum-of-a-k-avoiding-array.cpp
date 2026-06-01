class Solution {
public:
    int minimumSum(int n, int k) {
        int count=0;
        int sum=0;
        unordered_set<int>st;
        int i=0;
        while(count<n){
            i++;
            if(st.count(k-i))continue;
            st.insert(i);
            sum+=i;
            count++;
        }
 return sum;   }
};