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
    int num;

public:
    int goodNodes(TreeNode* root) {
        num = 0;
        traversal (root, -101);
        return num;
    }
    void traversal (TreeNode * root, int greatest){
        if (root == nullptr)
            return;
        
        if (greatest <= root->val){
            num++;
            greatest = root->val;
        }
        traversal (root->left, greatest);
        traversal (root->right, greatest);
        return ;
    }
};

// 中左右
// 遞迴傳遞 目前路過的參數 最大值
// 全域變數紀錄 目前 good node 樹
