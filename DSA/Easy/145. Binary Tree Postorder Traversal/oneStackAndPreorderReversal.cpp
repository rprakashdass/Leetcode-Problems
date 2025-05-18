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
            stack<TreeNode*> st;
            TreeNode* current = root;
            st.push(root);
            while(current || !st.empty()){
                current = st.top();
                st.pop();
                if(current->left) st.push(current->left);
                if(current->right) st.push(current->right);
                result.push_back(current->val);
                current = current->right;
            }
            reverse(result.begin(), result.end());
            return result;
        }
};
