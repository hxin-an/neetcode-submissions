class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i,int j, int& island_size){
        grid[i][j] = 0;
        island_size++;

        if( i>0 and grid[i-1][j] == 1){
            dfs(grid,i-1,j,island_size);
        }
        if( i+1<grid.size() and grid[i+1][j] == 1){
            dfs(grid,i+1,j,island_size);
        }
        if( j>0 and grid[i][j-1] == 1){
            dfs(grid,i,j-1,island_size);
        }
        if( j+1<grid[0].size() and grid[i][j+1] == 1){
            dfs(grid,i,j+1,island_size);
        }
        return ; 
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_size = 0, island_size = 0;

        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if( grid[i][j] == 1){
                    dfs(grid,i,j,island_size);
                    max_size = max(max_size,island_size);
                    island_size = 0;
                }
            }
        }

        return max_size;
    }
};


// 逐個掃 dfs  用 island size 紀錄最大值