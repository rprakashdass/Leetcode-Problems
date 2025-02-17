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
    void getLeaves(TreeNode* root, vector<int>& result){
        if(!root->left && !root->right) {
            result.push_back(root->val);
            return;
        }
        if(root->left) getLeaves(root->left, result);
        if(root->right) getLeaves(root->right, result);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res, res1;
        getLeaves(root1, res);
        cout << endl;
        getLeaves(root2, res1);
        return res == res1;
    }
};
