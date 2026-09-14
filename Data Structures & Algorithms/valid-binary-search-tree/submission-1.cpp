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
    vector <int> num;

public:
    bool isValidBST(TreeNode* root) {
        traversal (root);

        for(int i = 0; i < num.size() - 1;i++){
            if(num[i] >= num[i+1])
                return false;
        }
        return true;
    }

    void traversal (TreeNode * root){
        if ( root == nullptr)
            return;
        traversal (root->left);
        num.push_back(root->val);
        traversal (root->right);

        return;
    }
};
