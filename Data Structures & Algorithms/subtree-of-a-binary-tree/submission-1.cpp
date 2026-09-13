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
    bool find;
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        find = false;
        traversal(root, subRoot);
        return find;
    }

    void traversal( TreeNode * root, TreeNode * subRoot){
        if (root == nullptr or find == true)
            return ;
        
        if ( root->val == subRoot->val)
            find = sameTree(root, subRoot);
        
        traversal(root->left, subRoot);
        traversal(root->right, subRoot);

        return;
    }

    bool sameTree(TreeNode * root, TreeNode * subRoot ){
        if(root == nullptr and subRoot == nullptr)
            return true;
        else if ( (root == nullptr and subRoot != nullptr) or (root != nullptr and subRoot == nullptr) )
            return false;

        if(root->val != subRoot->val)
            return false;

        return sameTree(root->right,subRoot->right) and sameTree(root->left,subRoot->left) ; 
    }
};

// 中 左右
// 比對 root 和 subroot 一樣 進到比對一樣的函式