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
    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& result) {
        if(!root) return;

        // Add current node to path
        path.push_back(root->val);

        // If leaf and sum matches, store the path
        if (!root->left && !root->right && targetSum == root->val) {
            result.push_back(path);
        } else {
            // Recurse down children with updated sum
            dfs(root->left, targetSum - root->val, path, result);
            dfs(root->right, targetSum - root->val, path, result);
        }

        // Backtrack: remove current node before returning
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, path, result);
        return result;
    }
};