class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n = 100;
        vector<bool> prime(n + 1, true);
        prime[0]=prime[1]=false;
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {

                // marking as false
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        int m = nums.size();
        int minIdx = m;
        int maxIdx = -1;

        for(int i=0;i<m;i++){
            if(prime[nums[i]]){
              minIdx = min(minIdx,i);
              maxIdx = max(maxIdx,i);
            }
        }



    return maxIdx-minIdx;}
};