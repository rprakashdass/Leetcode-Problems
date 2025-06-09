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
    int dfs(TreeNode* root, unordered_map<long long, int> prefixSum, int targetSum, long long currentSum){
        if(!root) return 0;
        currentSum += root->val;
        int pathCount = prefixSum[currentSum - targetSum]; 
        prefixSum[currentSum] += 1;
        pathCount += dfs(root->left, prefixSum, targetSum, currentSum);
        pathCount += dfs(root->right, prefixSum, targetSum, currentSum);
        prefixSum[currentSum] -= 1;
        return pathCount;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSum;
        prefixSum[0] = 1;
        return dfs(root, prefixSum, targetSum, 0);
    }
};
