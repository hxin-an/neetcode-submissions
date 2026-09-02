class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> blocks(9);

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char value = board[row][col];

                if (value == '.') {
                    continue;
                }

                int block = (row / 3) * 3 + col / 3;

                if (!rows[row].insert(value).second ||
                    !cols[col].insert(value).second ||
                    !blocks[block].insert(value).second) {
                    return false;
                }
            }
        }

        return true;
    }
};