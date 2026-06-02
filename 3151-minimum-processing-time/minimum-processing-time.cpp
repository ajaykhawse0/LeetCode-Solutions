class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end(), greater<int>());

        int ans = INT_MIN;
        int n = tasks.size();
        int k = 0;
        for (int processor : processorTime) {

            int val = 4;
            int curr  = INT_MIN;

            while (val > 0 && k<n) {
                if (k >= n)
                    break;

               curr = max(curr,processor+tasks[k]);
               val--;
               k++;     
            }

            ans = max(curr,ans);
        }
 return ans;   }
};