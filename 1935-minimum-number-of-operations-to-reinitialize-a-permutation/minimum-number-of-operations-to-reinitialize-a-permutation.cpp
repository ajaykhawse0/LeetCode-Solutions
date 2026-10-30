class Solution {
public:
    int reinitializePermutation(int n) {
        int ans = 0;
        int i  = 1;

        while(ans==0||i>1){
            i = i*2%(n-1);
            ans++;
        }

        return ans;
    }
};