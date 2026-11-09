class Solution {
public:
    using T = tuple<int, int, int>;
    bool canRemoveAll(vector<int>& types, vector<int>& colors,
                      vector<int>& groupSize) {
        stack<T> st;

        int n = types.size();

        for (int i = 0; i < n; i++) {
            int type = types[i];
            int color = colors[i];
            if (!st.empty()) {
                auto [currT, currCol, sz] = st.top();
                st.pop();
                if (currT == type && currCol == color) {
                    sz++;
                    st.push({currT, currCol, sz});
                } else {
                    st.push({currT, currCol, sz});

                    // new

                    st.push({type, color, 1});
                }

            } else {
                // when st is empty
                st.push({type, color, 1});
            }

            auto [currT, currCol, sz] = st.top();
            if (sz == groupSize[currT])
                st.pop();
        }
        return st.empty();
    }
};