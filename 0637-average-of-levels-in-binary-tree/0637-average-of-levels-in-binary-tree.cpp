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
    // USING BFS
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root) return ans;

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            double avg = 0;

            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                avg += node -> val;

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            ans.push_back(avg / size);
        }

        return ans;
    }
};