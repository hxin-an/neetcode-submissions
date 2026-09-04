class Solution {
public:
    bool searchMatrix(
        vector<vector<int>>& matrix,
        int target
    ) {
        int row = matrix.size() - 1;


        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] > target) {
                row = i - 1;
                break;
            }
        }

 
        if (row < 0) {
            return false;
        }

        int l = 0;
        int r = matrix[row].size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (target == matrix[row][mid]) {
                return true;
            } else if (target > matrix[row][mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }
};