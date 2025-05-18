// Time Complexicity : O(N)
// Space Complexicity : O(N) stack space

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
    void dfs(TreeNode* root, int targetSum, vector<vector<int>> &result, vector<int> &path){
        if(!root) return;
        targetSum -= root->val;
        path.push_back(root->val);
        if(!root->left && !root->right && targetSum == 0){
            result.push_back(path);
        } else {
            dfs(root->left, targetSum, result, path);
            dfs(root->right, targetSum, result, path);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, result, path);
        return result;
    }
};
