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
    void dfs(TreeNode* root, int k, priority_queue<int>& maxHeap) {
        if(!root) return;
        if(maxHeap.size() < k){
            maxHeap.push(root->val);
        } else if (root->val < maxHeap.top()) {
            maxHeap.pop();
            maxHeap.push(root->val);
        } else {
            return;
        }
        dfs(root->left, k, maxHeap);
        dfs(root->right, k, maxHeap);
    }

    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> maxHeap;
        dfs(root, k, maxHeap);
        return maxHeap.top();
    }
};
