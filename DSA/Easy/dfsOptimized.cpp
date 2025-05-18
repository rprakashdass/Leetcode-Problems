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
    int maxDepth(TreeNode* root, int depth){
        if(!root) return 0;
        int left = maxDepth(root->left, depth + 1);
        if(left == -1) return -1;
        int right = maxDepth(root->right, depth + 1);
        if(right == -1) return -1;
        if (abs(left - right) > 1) return -1;
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        return maxDepth(root, 0) != -1;
    }
};
