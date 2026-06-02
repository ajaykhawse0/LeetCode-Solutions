class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size(); 
        vector<int>ans(n,0);

        if(k==0)return ans;

        else if(k<0){
            for(int i=0;i<n;i++){
            int val = k;
            int idx = i-1;
            int sum =0;

            while(val!=0){
                sum += code[(n+idx)%n];
                val++;
                idx--;
            }

            ans[i] = sum;
            
            }
        }
        else {
            for(int i=0;i<n;i++){
            int val = k;
            int idx = i+1;
            int sum =0;

            while(val!=0){
                sum += code[(idx)%n];
                val--;
                idx++;
            }

            ans[i] = sum;
            
            }
        }

   return ans; }
};