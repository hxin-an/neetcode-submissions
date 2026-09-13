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
    bool balance = true;
public:
    bool isBalanced(TreeNode* root) {
        height(root);
        return balance;
    }

    int height(TreeNode * root){
        if ( root == nullptr or balance == false)
            return 0;
        int left = height(root->left);
        int right = height(root->right);

        if ( abs(left - right) > 1){
            balance = false;
        }
        return max(left , right) + 1; 
    }
};

// 左 右 中 
// 比較樹高，用全域變數紀錄是否 balanced 