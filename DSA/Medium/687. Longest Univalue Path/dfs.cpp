// Time Complexity: O(N), where N is the number of nodes
// Space Complexity: O(H), where H is the height of the tree (O(N) in worst case, O(log N) in best case)

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
    int dfs(TreeNode* root, int &longest){
        if(!root) return 0;
        int left = dfs(root->left, longest);
        int right = dfs(root->right, longest);
        int leftPath = 0, rightPath = 0;
        if(root->left && root->val == root->left->val) {
            leftPath = 1 + left;
        }
        if(root->right && root->val == root->right->val) {
            rightPath = 1 + right;
        }
        longest = max(longest, leftPath + rightPath);
        return max(leftPath, rightPath);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int longest = 0;
        dfs(root, longest);
        return longest;
    }
};
