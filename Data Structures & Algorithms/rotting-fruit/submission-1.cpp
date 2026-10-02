class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue <int> q;
        int ans = 0;

        int m = grid.size();
        int n = grid[0].size();

        int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0}};

        // 把所有壞香蕉放進 queue
        for (int i = 0 ;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 2)
                    q.push(n*i+j);
            }
        } 

        while(!q.empty()){
            int q_size = q.size();
            bool spread = false;

            for(int k = 0; k<q_size;k++){ 
                int i = q.front()/n;
                int j = q.front()%n;
                q.pop();
                
                for(auto a:dir){
                    int n_i = i + a[0];
                    int n_j = j + a[1];
                    if( n_i >= 0 and n_i < m and n_j < n and n_j >= 0 and grid[n_i][n_j] == 1 ){
                        grid[n_i][n_j] = 2;
                        q.push(n*n_i+n_j);
                        spread = true;
                    }
                }
            }
            if(spread)
                ans++;

        }

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }

        return ans;
    }
};

// bfs 算 最短距離散佈完