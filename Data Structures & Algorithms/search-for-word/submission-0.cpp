class Solution {
private:
    bool ans;

    void backtrack(vector<vector<char>> &board, string& word, vector<vector<char>>& used,int index,int target){
        if(ans == true or index == word.size()){
            return;
        }

        int i = target / board[0].size();
        int j = target % board[0].size();

        if( board[i][j] != word[index]){
            return;
        }
        if(index == word.size()-1){
            ans = true;
            return;
        }
        used[i][j] = 1;
        
        if(i>0 and used[i-1][j] == 0){
            backtrack(board,word,used,index+1,(i-1)*board[0].size()+j);
        }
        if(i+1<board.size() and used[i+1][j] == 0){
            backtrack(board,word,used,index+1,(i+1)*board[0].size()+j);
        }
        if(j>0 and used[i][j-1] == 0){
            backtrack(board,word,used,index+1,i*board[0].size()+j-1);
        }
        if(j+1<board[0].size() and used[i][j+1] == 0){
            backtrack(board,word,used,index+1,i*board[0].size()+j+1);
        }

        used[i][j] = 0;
        return;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<char>> used(board.size(),vector<char>(board[0].size(),0));
        ans = false;

        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                backtrack(board,word,used,0,i*board[0].size()+j);
            }
        }

        return ans;
    }
};

// 每格做一次dfs 然後做剪枝
