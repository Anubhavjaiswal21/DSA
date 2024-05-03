class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int color) {
        if (color == image[sr][sc]) {
            return image;
        }
        int original = image[sr][sc];
        int m = image.size(), n = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                pair<int, int> current = q.front();
                q.pop();
                int currX = current.first, currY = current.second;
                image[currX][currY] = color;
                vector<int> dx = {-1, 0, 1, 0};
                vector<int> dy = {0, -1, 0, 1};
                for (int i = 0; i < 4; i++) {
                    int x = currX + dx[i], y = currY + dy[i];
                    if (x >= 0 && x < m && y >= 0 && y < n &&
                        image[x][y] == original) {
                        q.push({x, y});
                    }
                }
            }
        }
        return image;
    }
};
