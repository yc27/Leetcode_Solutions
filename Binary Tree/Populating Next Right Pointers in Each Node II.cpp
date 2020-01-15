/*
    Runtime: 20 ms
    Memory Usage: 19.8 MB
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
        Node *node = root, *head = NULL, *curr = NULL;
        
        while(node) {
            if(node->left) {
                if(head == NULL)
                    head = curr = node->left;
                
                else
                    curr = curr->next = node->left;
            }
            
            if(node->right) {
                if(head == NULL)
                    head = curr = node->right;
                
                else
                    curr = curr->next = node->right;
            }
            
            node = node->next;
            if(node == NULL) {
                node = head;
                head = curr = NULL;
            }
        }
        
        return root;
    }
};