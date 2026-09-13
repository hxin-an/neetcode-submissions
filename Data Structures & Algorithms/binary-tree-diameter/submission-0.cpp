/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int ans = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);

        return ans;
    }

    int height ( TreeNode* root){
        if (root == nullptr)
            return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        ans = max (ans, left + right);

        return 1 + max (right,left);
    }
};

// 順序 左 右 中
// 比較方式 ： 左子樹 高度 加上 右子樹高度
