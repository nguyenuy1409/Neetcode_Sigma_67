class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rottenCoord;
        int freshFruit = 0;
        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[0].size() ; j++) {
                if(grid[i][j] == 1) {
                    freshFruit++;
                }
                if(grid[i][j] == 2) {
                    rottenCoord.push({i, j});
                }
            }
        }
        int rottenMinutes = 0;
        
        if(freshFruit == 0) return 0;

        while(!rottenCoord.empty()) {
            int levelSize = rottenCoord.size();

            bool infectedSuccess = false;

            int dR[] = {-1, 1, 0, 0};
            int dC[] = {0, 0, -1, 1};

            for(int i = 0 ; i < levelSize ; i++) {
                auto coord = rottenCoord.front();
                int dRow = coord.first;
                int dCol = coord.second;
                rottenCoord.pop();
                for(int a = 0 ; a < 4 ; a++) {
                    int newRow = dRow + dR[a];
                    int newCol = dCol + dC[a];

                    if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[newRow].size() && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        freshFruit--;
                        rottenCoord.push({newRow, newCol});
                        infectedSuccess = true;
                    }
                }
            }
            if(infectedSuccess) rottenMinutes++;
        }
        if(freshFruit!=0) return -1;
        return rottenMinutes;
    }
};
