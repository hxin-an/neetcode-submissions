class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int len = inorder.size();

        for (int i = 0; i < len; i++) {
            mp[inorder[i]] = i;
        }

        return build(mp, preorder, 0, len - 1,
                     inorder, 0, len - 1);
    }

    TreeNode* build(
        unordered_map<int, int>& mp,
        vector<int>& preorder,
        int pre_l,
        int pre_r,
        vector<int>& inorder,
        int in_l,
        int in_r
    ) {
        if (pre_l > pre_r)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[pre_l]);

        int mid_index = mp[preorder[pre_l]];

        int left_size = mid_index - in_l;

        root->left = build(
            mp,
            preorder,
            pre_l + 1,
            pre_l + left_size,
            inorder,
            in_l,
            mid_index - 1
        );

        root->right = build(
            mp,
            preorder,
            pre_l + left_size + 1,
            pre_r,
            inorder,
            mid_index + 1,
            in_r
        );

        return root;
    }
};