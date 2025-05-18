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
    void dfsFromNode(TreeNode* root, long targetSum, int &count){
        if(!root) return;
        targetSum -= root->val;
        if(targetSum == 0) count++;
        dfsFromNode(root->left, targetSum, count);
        dfsFromNode(root->right, targetSum, count);
    }
    void dfs(TreeNode* root, int targetSum, int &count){
        if(!root) return;
        dfsFromNode(root, targetSum, count);
        dfs(root->left, targetSum, count);
        dfs(root->right, targetSum, count);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        dfs(root, targetSum, count);
        return count;
    }
};
