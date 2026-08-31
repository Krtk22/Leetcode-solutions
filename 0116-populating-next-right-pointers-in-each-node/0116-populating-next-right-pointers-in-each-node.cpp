/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        // Boundry condition,
        if (!root) return NULL;

        // Queue for level order traversal
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {

            int levelSize = q.size();            
            Node* prev = nullptr;

            for (int i = 0; i < levelSize; ++i) {

                Node* curr = q.front();
                q.pop();

                if (prev) {
                    prev->next = curr;  // connect previous node to current
                }
                
                prev = curr;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                
            }
        }
        
        return root;

    }
};