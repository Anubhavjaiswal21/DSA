class Solution {
public:

    vector<int> offsets = {0, 1, 0, -1, 0};
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        unordered_map<int, int> area;

        int maxArea = 0;
        int currArea = 0;
        int island_id = 2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {

                    calc(grid, i, j, currArea, n, island_id);
                    maxArea = max(maxArea, currArea);
                    area[island_id] = currArea;
                    currArea = 0;
                    island_id++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> st;
                    for (int k = 0; k < 4; k++) {
                        int x = i + offsets[k];
                        int y = j + offsets[k + 1];
                        if (x < 0 || y < 0 || x >= n || y >= n ||
                            grid[x][y] == 0)
                            continue;
                        st.insert({grid[x][y]});
                    }

                    int total = 1;
                    for (auto i : st) {
                        total += area[i];
                    }
                    maxArea = max(maxArea, total);
                }
            }
        }

        return maxArea;
    }

    void calc(vector<vector<int>>& grid, int i, int j, int& currArea, int& n,
              int& island_id) {
        currArea++;
        grid[i][j] = island_id;
        for (int k = 0; k < 4; k++) {
            int x = i + offsets[k];
            int y = j + offsets[k + 1];
            if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 1)
                continue;
            calc(grid, x, y, currArea, n, island_id);
        }
    }
};
