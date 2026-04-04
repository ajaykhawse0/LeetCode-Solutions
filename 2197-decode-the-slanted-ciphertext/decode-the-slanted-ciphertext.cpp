class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (n == 0) return "";

        int cols = n / rows;
        vector<vector<char>> grid(rows, vector<char>(cols));

        int k = 0;

        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = encodedText[k++];
            }
        }

        string result = "";

        // Traverse diagonally
        for (int j = 0; j < cols; j++) {
            int row = 0, col = j;

            while (row < rows && col < cols) {
                result += grid[row][col];
                row++;
                col++;
            }
        }

        
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};