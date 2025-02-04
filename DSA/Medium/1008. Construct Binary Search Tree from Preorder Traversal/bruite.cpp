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
private:
    TreeNode* insert(TreeNode* root, int data){
        if(root == nullptr) return new TreeNode(data);
        if(data > root->val) {
            root->right = insert(root->right, data);
        } else{
            root->left = insert(root->left, data);
        }
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int n  = preorder.size();
        for(int i = 1;i < n;i++){
            root = insert(root, preorder[i]);
        }
        return root;
    }
};
