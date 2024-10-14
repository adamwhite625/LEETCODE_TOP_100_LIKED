class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_oranges = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh_oranges++;
                }
            }
        }
        if (fresh_oranges == 0) return 0;

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int minutes = 0;
        while (!q.empty()) {
            int size = q.size();
            bool any_rotten = false;

            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : directions) {
                    int newX = x + dx;
                    int newY = y + dy;
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                        fresh_oranges--;
                        any_rotten = true;
                    }
                }
            }

            if (any_rotten) {
                minutes++;
            }
        }
        return fresh_oranges == 0 ? minutes : -1;
    }
};
