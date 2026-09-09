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
    // USING MULTISETS
public:
    void DFS(TreeNode* root, multiset<int>& list) {
        if(!root) return;
        list.insert(root->val);
        DFS(root->left, list);
        DFS(root->right, list);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        multiset<int> list1, list2;

        DFS(root1, list1);
        DFS(root2, list2);

        // Merge
        list1.insert(list2.begin(), list2.end());

        return vector<int>(list1.begin(), list1.end());
    }
};