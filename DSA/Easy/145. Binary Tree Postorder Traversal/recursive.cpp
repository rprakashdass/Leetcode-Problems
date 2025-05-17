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
        void postOrder(vector<int> &result, TreeNode* root){
            if(!root) return;
            postOrder(result, root->left);
            postOrder(result, root->right);
            result.push_back(root->val);
        }
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> result;
            postOrder(result, root);
            return result;
        }
};
