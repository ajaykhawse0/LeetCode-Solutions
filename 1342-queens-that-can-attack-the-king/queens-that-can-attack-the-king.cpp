class Solution {
public:
    vector<vector<int>> bottomMoves = {{1, 1},
                                       {1, -1}}; // bottom right,bottom left
    vector<vector<int>> topMoves = {{-1, 1}, {-1, -1}}; // top right,top left
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens,
                                            vector<int>& king) {
        vector<vector<int>> board(8, (vector<int>(8, 0)));
        board[king[0]][king[1]] = 1;
        for (auto& q : queens) {
            board[q[0]][q[1]] = -1;
        }

        vector<vector<int>> ans;

        for (auto& q : queens) {
            bool attacked = false;
            // move down the col
            for (int i = q[0] + 1; i < 8; i++) {
                if (board[i][q[1]] == 1) {
                    attacked = true;
                    break;
                } else if (board[i][q[1]] == -1) {
                    break;
                }
            }

            if (!attacked) {
                // move l->r
                for (int i = q[1] + 1; i < 8; i++) {
                    if (board[q[0]][i] == 1) {
                        attacked = true;
                        break;
                    } else if (board[q[0]][i] == -1) {
                        break;
                    }
                }
            }
            if (!attacked) {
                // move r<-l
                for (int i = q[1] - 1; i >= 0; i--) {
                    if (board[q[0]][i] == 1) {
                        attacked = true;
                        break;
                    } else if (board[q[0]][i] == -1) {
                        break;
                    }
                }
            }

            if (!attacked) {
                // move up the col
                for (int i = q[0] - 1; i >= 0; i--) {
                    if (board[i][q[1]] == 1) {
                        attacked = true;
                        break;
                    } else if (board[i][q[1]] == -1) {
                        break;
                    }
                }
            }
            // diagonals
            if (!attacked) {
                // bottom right move

                int nr = q[0] + 1;
                int nc = q[1] + 1;

                while (nr < 8 && nc < 8) {
                    if (board[nr][nc] == -1)
                        break;

                    if (board[nr][nc] == 1) {
                        attacked = true;
                        break;
                    }

                    nr++;
                    nc++;
                }
            }
            if (!attacked) {
                // bottom left move
                int nr = q[0] + 1;
                int nc = q[1] - 1;

                while (nr < 8 && nc > -1 ) {
                    if (board[nr][nc] == -1)
                        break;

                    if (board[nr][nc] == 1) {
                        attacked = true;
                        break;
                    }

                    nr++;
                    nc--;
                }
            }
            if (!attacked) {
                // top left move
                int nr = q[0] - 1;
                int nc = q[1] - 1;

                while (nr > -1 && nc > -1 ) {
                    if (board[nr][nc] == -1)
                        break;

                    if (board[nr][nc] == 1) {
                        attacked = true;
                        break;
                    }

                    nr--;
                    nc--;
                }
            }
            if (!attacked) {
                // top right move
                int nr = q[0] - 1;
                int nc = q[1] + 1;

                while (nr > -1 && nc < 8 ) {
                    if (board[nr][nc] == -1)
                        break;

                    if (board[nr][nc] == 1) {
                        attacked = true;
                        break;
                    }

                    nr--;
                    nc++;
                }
            }

            if (attacked) {
                ans.push_back(q);
            }
        }
        return ans;
    }
};