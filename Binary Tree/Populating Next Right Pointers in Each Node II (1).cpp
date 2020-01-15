/*
    Runtime: 408 ms
    Memory Usage: 66.3 MB
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;

        Node *node = root->next, *nextNode = NULL;
        while(node != NULL && nextNode == NULL) {
            if(node->left != NULL) {
                nextNode = node->left;
                break;
            }

            if(node->right != NULL) {
                nextNode = node->right;
                break;
            }

            node = node->next;
        }
        
        if(root->right != NULL)
            root->right->next = nextNode;
        
        if(root->left != NULL)
            root->left->next = root->right == NULL ? nextNode : root->right;
        
        connect(root->right);
        connect(root->left);
        return root;
    }
};