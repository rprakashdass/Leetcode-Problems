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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        queue<pair<TreeNode*, TreeNode*>> qu;
        qu.push({p, q});
        while(!qu.empty()){
            for(int i = qu.size();i > 0;i--){
                auto [a, b] = qu.front();
                qu.pop();

                if(a->val != b->val) return false;
                if((!a->left && b->left) || (a->left && !b->left)) return false;
                if((!a->right && b->right) || (a->right && !b->right)) return false;

                if(a->left && b->left) qu.push({a->left, b->left});
                if(a->right && b->right) qu.push({a->right, b->right});
            }
        }
        return true;
    }
};
