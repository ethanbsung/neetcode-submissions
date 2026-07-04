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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        int goods = 1;
        int maxVal = root->val;
        
        goods += dfs(root->left, maxVal);
        goods += dfs(root->right, maxVal);

        return goods;
    }

    int dfs(TreeNode* root, int maxVal) {
        if (!root) return 0;

        if (root->val >= maxVal) {
            maxVal = root->val;
            return 1 + dfs(root->left, maxVal) + dfs(root->right, maxVal);
        } else {
            return dfs(root->left, maxVal) + dfs(root->right, maxVal);
        }
    }
};
