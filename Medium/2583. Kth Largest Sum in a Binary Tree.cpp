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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> result;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
           int n = queue.size();
           long long sum = 0;
           while(n--){
                TreeNode* node = queue.front();
                queue.pop();
                sum += (long long)node->val;

                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
           }
           result.push_back(sum);
        }
        if(k > result.size()) return -1; 
        sort(result.begin(), result.end(), greater<long long>());
        return result[k-1];
    }
};
