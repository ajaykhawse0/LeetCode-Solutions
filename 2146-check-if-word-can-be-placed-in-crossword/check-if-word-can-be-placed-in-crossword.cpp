class Solution {
public:
    int m, n;
    string word;
    vector<vector<char>> b;
    bool check(string temp) {
        bool valid = true;
        for (int i = 0; i < word.size(); i++) {
            if (temp[i] != ' ' && temp[i] != word[i]) {
                valid = false;
                break;
            }
        }
        if (valid)
            return true;
        valid = true;
        // try from back
        for (int i = 0; i < word.size(); i++) {
            if (temp[i] != ' ' && temp[i] != word[word.size() - i - 1]) {
                valid = false;
                break;
            }
        }
        if (valid)
            return true;
        return false;
    }

    bool H() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] == '#')
                    continue;

                if (b[i][j] == ' ' || b[i][j] == word[0] ||
                    b[i][j] == word[word.size() - 1]) {
                    string temp = "";
                    while (j < n && b[i][j] != '#') {
                        temp += b[i][j];
                        j++;
                    }
                    if (temp.size() == word.size()) {
                        if (check(temp))
                            return true;
                    }
                }
                else{
                    //remove trailing spaces
                    while(j<n && b[i][j] != '#'){
                        j++;
                    }
                }
            }
        }
    return false;}
    bool V() {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (b[i][j] == '#')
                    continue;

                if (b[i][j] == ' ' || b[i][j] == word[0] ||
                    b[i][j] == word[word.size() - 1]) {
                    string temp = "";
                    while (i < m && b[i][j] != '#') {
                        temp += b[i][j];
                        i++;
                    }
                    if (temp.size() == word.size()) {
                        if (check(temp))
                            return true;
                    }
                }
                else{
                    //remove trailing spaces
                    while(i<m && b[i][j] != '#'){
                        i++;
                    }
                }
            }
        }
    return false;}
    bool placeWordInCrossword(vector<vector<char>>& board, string w) {
        // Brute Force for Rescue;
        m = board.size();
        n = board[0].size();
        b = board;

        word = w;

        // try placing horizontally
        if (H())
            return true;
        b = board;    
        // try placing VERTICALLY
        if (V())
            return true;
   return false; }
};