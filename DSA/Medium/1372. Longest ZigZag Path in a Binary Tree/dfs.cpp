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
    void dfs(TreeNode* root, bool left, int length, int &longest) {
        if(!root) return;
        longest = max(longest, length);
        if(left) {
            dfs(root->left, false, length + 1, longest);
            dfs(root->right, true, 1, longest);
        } else {
            dfs(root->right, true, length + 1, longest);
            dfs(root->left, false, 1, longest);
        }
    }
    int longestZigZag(TreeNode* root) {
        int longest = 0;
        dfs(root, true, 0, longest);
        dfs(root, false, 0, longest);
        return longest;
    }
};
