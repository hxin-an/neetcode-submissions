class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        // 所有 treasure 同時作為 BFS 起點
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        int dir[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            for(auto& d : dir){
                int ni = i + d[0];
                int nj = j + d[1];

                if(ni >= 0 && ni < m &&
                   nj >= 0 && nj < n &&
                   grid[ni][nj] == INT_MAX){

                    grid[ni][nj] = grid[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
    }
};