class Solution {
public:
    using T = tuple<int, int, string>;
    string arrangeWords(string text) {
        priority_queue<T, vector<T>, greater<T>> pq;
        text[0] = tolower(text[0]);
        stringstream ss(text);
        string str;
        int idx = 0;
        while (ss >> str) {
            pq.push({str.length(), idx, str});
            idx++;
        }

        string ans;

        while (!pq.empty()) {
            auto [len, i, word] = pq.top();
            pq.pop();

            if (ans.empty()) {
                word[0] = toupper(word[0]);
            }
            if (!ans.empty()) {
                ans += " ";
            }
            ans += word;
        }

        return ans;
    }
};