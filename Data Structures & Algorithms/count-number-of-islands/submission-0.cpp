class Solution {
private:
    void dfs(vector<vector<char>>&grid, int i,int j,int & one_nums){
        one_nums--;
        grid[i][j] = 0;
        cout << i << " " << j << endl;

        if(i > 0 and grid[i-1][j] == '1')
            dfs (grid,i-1,j,one_nums);
        if(i + 1 < grid.size() and grid[i+1][j] == '1')
            dfs (grid,i+1,j,one_nums);
        if(j > 0  and grid[i][j-1] == '1')
            dfs (grid,i,j-1,one_nums);
        if(j + 1 < grid[0].size()  and grid[i][j+1] == '1')
            dfs (grid,i,j+1,one_nums);
        
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int one_nums = 0,ans = 0;

        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == '1')
                    one_nums++;
            }
        }

        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(one_nums == 0)
                    break;
                if(grid[i][j] == '1'){
                    dfs(grid,i,j,one_nums);
                    ans++;
                } 
            }
        }

        return ans;
    }
};

// 1 's num 判斷還要不要在 執行 dfs
// ans 紀錄 島數量
// 算多少個 1
// 歸零前 做 dfs 每次 dfs ans + 1
// return ans 