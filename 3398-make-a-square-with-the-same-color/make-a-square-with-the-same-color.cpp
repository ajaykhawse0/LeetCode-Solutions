class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int wCol = 0;
        int bCol = 0;

        // Square 1
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 1; j++) {

                if(grid[i][j]=='B')bCol++;
                else wCol++;
            }
        }

        if(bCol >= 3 || wCol >= 3)return true;
        bCol=0,wCol=0;

        // Square 2
        for (int i = 0; i <= 1; i++) {
            for (int j = 1; j <= 2; j++) {

                if(grid[i][j]=='B')bCol++;
                else wCol++;
            }
        }

        if(bCol >= 3 || wCol >= 3)return true;
        bCol=0,wCol=0;

        // Square 3
        for (int i = 1; i <= 2; i++) {
            for (int j = 0; j <= 1; j++) {

                if(grid[i][j]=='B')bCol++;
                else wCol++;
            }
        }

        if(bCol >= 3 || wCol >= 3)return true;
        bCol=0,wCol=0;

        // Square 4
        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= 2; j++) {

                if(grid[i][j]=='B')bCol++;
                else wCol++;
            }
        }

        if(bCol >= 3 || wCol >= 3)return true;
        bCol=0,wCol=0;

        return false;
    }
};