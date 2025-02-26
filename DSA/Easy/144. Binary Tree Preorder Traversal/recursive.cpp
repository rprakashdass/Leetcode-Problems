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
    void traversal(vector<int>& result, TreeNode* root){
        if(!root) return ;
        result.push_back(root->val);
        traversal(result, root->left);
        traversal(result, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(result, root);
        return result;
    }
};
