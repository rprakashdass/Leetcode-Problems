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
    bool dfs(TreeNode* leftTree, TreeNode* rightTree) {
        if(!leftTree && !rightTree) return true;
        if(!leftTree || !rightTree) return false;
        if(leftTree->val != rightTree->val) return false;
        if(!dfs(leftTree->left, rightTree->right) || !dfs(leftTree->right, rightTree->left)) {
            return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }
};
