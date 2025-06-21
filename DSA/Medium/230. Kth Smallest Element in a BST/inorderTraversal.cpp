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
    bool inorderTraversal(TreeNode* root, int k, int& smallest, int& count) {
        if(!root) return false;
        if(inorderTraversal(root->left, k, smallest, count)) return true;
        smallest = root->val;
        count++;
        if(count >= k) return true;
        if(inorderTraversal(root->right, k, smallest, count)) return true;
        return false;
    }

    int kthSmallest(TreeNode* root, int k) {
        int smallest = 0, count = 0;
        inorderTraversal(root, k, smallest, count);
        return smallest;
    }
};
