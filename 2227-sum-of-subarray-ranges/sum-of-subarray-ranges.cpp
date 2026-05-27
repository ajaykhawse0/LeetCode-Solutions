class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftMax(n), rightMax(n);
        vector<int> leftMin(n), rightMin(n);

        stack<int> st;

        // Previous Greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            leftMax[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        st = stack<int>();

        // Next Greater
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            rightMax[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        st = stack<int>();

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            leftMin[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        st = stack<int>();

        // Next Smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            rightMin[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long maxSum = 0, minSum = 0;

        for (int i = 0; i < n; i++) {
            maxSum += 1LL * nums[i] * leftMax[i] * rightMax[i];
            minSum += 1LL * nums[i] * leftMin[i] * rightMin[i];
        }

        return maxSum - minSum;
    }
};