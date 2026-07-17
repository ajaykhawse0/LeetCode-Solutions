class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        // for bfs use queue
      
       
        queue<pair<int, int>> q;

        q.push({entrance[0], entrance[1]});

        int moves = 1;

        int m = maze.size();

        int n = maze[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        vis[entrance[0]][entrance[1]] = true;

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                int r = q.front().first;
                int c = q.front().second;

                q.pop();

               

                for (auto& dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        maze[nr][nc] != '+' && !vis[nr][nc]) {
                             vis[nr][nc] = true;

                        if (nr == m - 1 || nc == n - 1 || nr == 0 || nc == 0)
                            return moves;

                        q.push({nr, nc});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};