class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int r = startPos[0] , c = startPos[1], re = homePos[0], ce = homePos[1], ans = 0;
        while(r < re) ans += rowCosts[++r];
        while(c < ce) ans += colCosts[++c];
        while(r > re) ans += rowCosts[--r];
        while(c > ce) ans += colCosts[--c];
        return ans;
        
    }
};
//TLE
// class Solution {
// public: 
//     vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
//     typedef pair<long long, pair<long long, long long>> P;
//     int minCost(vector<int>& startPos, vector<int>& homePos,
//                 vector<int>& rowCosts, vector<int>& colCosts) {

//         if (startPos[0] == homePos[0] && startPos[1] == homePos[1])
//             return 0;

//         long long m = rowCosts.size();

//         long long n = colCosts.size();

//         vector<vector<long long>> dist(m, vector<long long>(n, INT_MAX));
        
//         vector<vector<bool>> vis(m, vector<bool>(n, false));

//         priority_queue<P, vector<P>, greater<P>> pq;

//         dist[startPos[0]][startPos[1]] = 0;
//         pq.push({0, {startPos[0], startPos[1]}});

//         while (!pq.empty()) {
//             auto [cost, dim] = pq.top();
//             auto [r, c] = dim;
//             pq.pop();

//             if (r == homePos[0] && c == homePos[1])
//                 return cost;

//             if (cost > dist[r][c])
//                 continue;

//             if (vis[r][c])
//                 continue;

//             vis[r][c] = true;

//             for (auto& dir : dirs) {
//                 long long nr = r + dir[0];
//                 long long nc = c + dir[1];

//                 if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]) {

//                     long long newCost = cost;

//                     if (nr != r)
//                         newCost += rowCosts[nr];
//                     else
//                         newCost += colCosts[nc];

//                     if (newCost < dist[nr][nc]) {
//                         dist[nr][nc] = newCost;
//                         pq.push({newCost, {nr, nc}});
//                     }
//                 }
//             }
//         }
//         return dist[homePos[0]][homePos[1]];
//     }
// };