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
    int maxDepth(TreeNode* root, int depth, bool &flag){
        if(!root) return 0;
        int left = maxDepth(root->left, depth + 1, flag);
        int right = maxDepth(root->right, depth + 1, flag);
        if (abs(left - right) > 1) flag = false;
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool flag = true;
        maxDepth(root, 0, flag);
        return flag;
    }
};
