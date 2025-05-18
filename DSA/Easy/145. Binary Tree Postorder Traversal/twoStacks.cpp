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
        vector<int> postorderTraversal(TreeNode* root) {
            if(!root) return {};
            vector<int> result;
            stack<TreeNode*> st1, st2;
            TreeNode* current = root;
            st1.push(root);
            while(current || !st1.empty()){
                current = st1.top();
                st2.push(current);
                st1.pop();
                if(current->left) st1.push(current->left);
                if(current->right) st1.push(current->right);
                current = current->right;
            }
            while(!st2.empty()){
                result.push_back(st2.top()->val);
                st2.pop();
            }
            return result;
        }
};
