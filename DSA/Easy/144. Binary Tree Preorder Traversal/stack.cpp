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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> result;
        stack<TreeNode*> stq;
        stq.push(root);
        while(!stq.empty()){
            int size = stq.size();
            for(int i = 0;i < size;i++){
                TreeNode* node = stq.top();
                result.push_back(node->val);
                stq.pop();
                if(node->right) stq.push(node->right);
                if(node->left) stq.push(node->left);
            }
        }
        return result;
    }
};
