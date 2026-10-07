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
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        bool level = false; // false = even level, true = odd level

        while (!q.empty()) {
            int n = q.size();
            int prevVal = (level == false ? INT_MIN : INT_MAX);

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Parity check
                if (level == false && node->val % 2 == 0) return false; // even level → odd values
                if (level == true && node->val % 2 != 0) return false; // odd level → even values

                // Monotonicity check
                if (level == false && node->val <= prevVal) return false; // strictly increasing
                if (level == true && node->val >= prevVal) return false; // strictly decreasing

                prevVal = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level = !level; // toggle level
        }
        return true;
    }
};
