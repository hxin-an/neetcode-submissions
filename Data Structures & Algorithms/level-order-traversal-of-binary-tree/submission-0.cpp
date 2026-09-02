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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector <int> > ans;

        height (root, ans,0 );

        return ans;
    }

    void height (TreeNode* root , vector<vector <int> >& ans,int h){
        if ( root == nullptr)
            return;
        
        if(ans.size() < h + 1)
            ans.push_back( {} );
        ans[h].push_back (root->val);

        height(root->left, ans, h+1);
        height(root->right, ans, h+1);
        
        return;
    }

};
