class Solution {
public:
    using T = tuple<long long, int, int, int, int>;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; // U,B,R,L
    int minCost(vector<vector<int>>& grid, int k) {
        // vector<char> D = {'U', 'B', 'R', 'L'};
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<vector< long long >>>>dist(m,vector<vector<vector< long long >>>(n,vector<vector< long long >>(k+1,vector< long long >(4,LLONG_MAX))));//r,c,turns,dir

        
        
        priority_queue<T, vector<T>, greater<T>> pq; //,cost,r,c,turns,direction

        pq.push({grid[0][0], 0, 0, 0, 4}); // 4=start no impact

        while (!pq.empty()) {
            auto [cost, r, c, turns, currD] = pq.top();
            pq.pop();

           
            if (r == m - 1 && c == n - 1)
                return cost;

            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];

                if (nr >= m || nr < 0 || nc >= n || nc < 0)
                    continue;

                int newTurns = turns;

                if(currD !=4 && currD != i){
                    newTurns++;
                }

                if(newTurns>k)continue;

                int newCost = cost + grid[nr][nc];

                if(newCost < dist[nr][nc][newTurns][i]){
                    pq.push({
                        newCost,
                        nr,
                        nc,
                        newTurns,
                        i
                    });

                    dist[nr][nc][newTurns][i] = newCost;
                }
              
            }
        }

        return -1;
    }
};