class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        queue<pair<int, int>> coordinate;
        coordinate.push({i, j});
        visited[i][j] = true;

        int delX[] = {0, 0, -1, 1};
        int delY[] = {-1, 1, 0, 0};


        while(!coordinate.empty()) {
            auto pairCoord = coordinate.front();
            coordinate.pop();
            int coordX = pairCoord.first;
            int coordY = pairCoord.second;

            for(int a = 0 ; a < 4 ; a++) {
                int newX = coordX + delX[a];
                int newY = coordY + delY[a];

                if(newX >= 0 && newX < grid.size() && newY >=0 && newY < grid[newX].size()) {
                    if(grid[newX][newY] == '1' &&!visited[newX][newY]) {
                        visited[newX][newY] = true;
                        coordinate.push({newX, newY});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int islandsNumber = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[0].size() ; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    bfs(grid, i, j, visited);
                    islandsNumber++;
                }
            }
        }
        return islandsNumber;
    }
};
