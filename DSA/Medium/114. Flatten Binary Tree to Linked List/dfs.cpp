class Solution {
public:
    TreeNode* dfs(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* left = dfs(root->left);
        TreeNode* right = dfs(root->right);

        if (left) {
            root->right = left;
            root->left = nullptr;

            TreeNode* tail = left;
            while (tail->right) {
                tail = tail->right;
            }

            tail->right = right;
        } else {
            root->right = right;
        }

        return root;
    }

    void flatten(TreeNode* root) {
        dfs(root);
    }
};
