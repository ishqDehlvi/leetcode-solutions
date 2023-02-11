//1162. As Far from Land as Possible
// Date: 12 Feb, 2023


class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) 
                    q.push({i, j});
                else 
                    grid[i][j] = INT_MAX;
            }
        }
        if (q.empty() || q.size() == n * n) 
            return -1;
        int distance = -1;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int i = x + dx, j = y + dy;
                    if (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == INT_MAX) {
                        grid[i][j] = grid[x][y] + 1;
                        q.push({i, j});
                    }
                }
            }
            distance++;
        }
        return distance;
    }
};
