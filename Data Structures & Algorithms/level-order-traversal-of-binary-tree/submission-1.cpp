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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        int level = 0;
        runLevel(root, res, level);
        return res;
    }

    void runLevel(TreeNode* root, vector<vector<int>> &levList, int level) {
        if (!root) return;
        if (level == levList.size()) levList.push_back({});
        levList[level].push_back(root->val);
        int newLevel = level + 1;
        runLevel(root->left, levList, newLevel);
        runLevel(root->right, levList, newLevel);
    }

private:
    vector<vector<int>> res;
};
