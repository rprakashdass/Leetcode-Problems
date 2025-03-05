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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            deque<int> levelNodes;
            for(int _ = q.size();_ > 0;_--){
                TreeNode* node = q.front();
                q.pop();
                if(level%2 != 0){
                    levelNodes.push_front(node->val);
                } else {
                    levelNodes.push_back(node->val);
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            vector<int> temp;
            while(!levelNodes.empty()){
                temp.push_back(levelNodes.front());
                levelNodes.pop_front();
            }
            result.push_back(temp);
            level++;
        }
        return result;
    }
};
