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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        vector< stack <int> > st;
        height (st,root,0);

        for(auto a:st){
            ans.push_back(a.top());
        }        
        return ans;
    }

    void height( vector< stack<int> > &st, TreeNode * root,int h){
        if( root == nullptr)
            return;
        if(st.size() < h + 1)
            st.push_back({});

        st[h].push(root->val);

        height(st,root->left,h+1);
        height(st,root->right,h+1);

        return;
    }
};

// 中左右
// 每個 height 一個 stack 
