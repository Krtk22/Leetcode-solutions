/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL) return NULL;

        if(root == p || root == q) return root;

        TreeNode* left_node = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right_node = lowestCommonAncestor(root -> right, p, q);

        if(left_node != NULL && right_node != NULL) return root;

        if(left_node != NULL) return left_node;

        return right_node;
    }
};