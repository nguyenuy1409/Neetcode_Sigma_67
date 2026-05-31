class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int maxArea = 1;
        queue<pair<int, int>> coordinate;

        coordinate.push({i, j});
        visited[i][j] = true;

        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        while(!coordinate.empty()) {
            int levelSize = coordinate.size();
            for(int i = 0 ; i < levelSize ; i++) {
                auto coord = coordinate.front();
                coordinate.pop();

                int coordRow = coord.first;
                int coordCol = coord.second;

                for(int a = 0 ; a < 4 ; a++) {
                    int newRow = coordRow + dRow[a];
                    int newCol = coordCol + dCol[a];

                    if(newRow >= 0 && newRow < grid.size() && newCol >=0 && newCol < grid[newRow].size() && grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        coordinate.push({newRow, newCol});
                        maxArea++;
                    }
                }
            }
        }
        return maxArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[0].size() ; j++) {
                if(grid[i][j] && !visited[i][j]) {
                    int currArea = bfs(grid, i, j, visited);
                    res = max(res, currArea);
                }
            }
        }
        return res;
    }
};
