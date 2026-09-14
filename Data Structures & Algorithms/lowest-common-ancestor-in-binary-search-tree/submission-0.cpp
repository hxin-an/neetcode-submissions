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
    TreeNode * target = nullptr;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traversal(root,p,q);
        return target;
    }

    bool traversal(TreeNode * root, TreeNode * p, TreeNode * q){
        if ( root == nullptr )
            return false;

        bool left = traversal(root->left,p,q);
        bool right = traversal(root->right,p,q);
        bool current = (root == p) or (root == q);

        if (left + right + current >= 2 && target == nullptr)
            target = root;
        
        return left or right or current;
    }
};

// 左右中
// 判斷 左 右 存在 p q  全域變數 變 值 和 bool 變 tue 減枝
