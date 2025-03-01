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
    void lookup(TreeNode* root, int X, int& count){
        if(!root) return;
        if(root->val >= X){
            X = root->val;
            count++;
        }
        lookup(root->left, X, count);
        lookup(root->right, X, count);
    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        lookup(root, root->val, count);
        return count;
    }
};
