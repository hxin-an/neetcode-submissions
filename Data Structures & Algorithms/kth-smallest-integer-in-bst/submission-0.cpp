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
    int counter;
    int val;

public:
    int kthSmallest(TreeNode* root, int k) {
        counter = k;
        traversal(root);
        return val;
    }

    void traversal ( TreeNode* root){
        if (root == nullptr or counter == 0)
            return ;
        
        traversal(root->left);
        
        if(counter == 1)
            val = root->val;
        counter--;

        traversal(root->right);

        return;
    }
};

// 左中右
// 全域計數器
