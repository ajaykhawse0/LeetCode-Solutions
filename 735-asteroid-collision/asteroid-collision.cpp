class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int a : asteroids) {
            if (st.empty()) {
                st.push(a);
            }

            else if (st.top() > 0 && a < 0) {
                if (abs(a) == st.top())
                    st.pop();
                else if (abs(a) > st.top()) {
                    while (!st.empty() && st.top() > 0 && st.top() < abs(a)) {
                        st.pop();
                    }
                    if (st.empty() || st.top() < 0)
                        st.push(a);
                    else if (st.top() == abs(a))
                        st.pop();
                }
            } else {
                st.push(a);
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};