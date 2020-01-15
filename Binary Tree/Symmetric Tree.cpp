/*
    Runtime: 4 ms
    Memory Usage: 14.9 MB
*/

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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> l, r;
        TreeNode *x = new TreeNode(0), *y = new TreeNode(0);
        
        if(!root)
            return 1;
        
        if(root->left)
            l.push(root->left);
        if(root->right)
            r.push(root->right);

        while(!l.empty() && !r.empty()) {
            x = l.front();
            l.pop();
            
            y = r.front();
            r.pop();
            
            if(x->val != y->val)
                return 0;
            
            if(x->left != NULL && y->right != NULL) {
                l.push(x->left);
                r.push(y->right);
            }

            if(x->right != NULL && y->left != NULL) {
                l.push(x->right);
                r.push(y->left);
            }
            
            if((x->right == NULL && y->left != NULL) || (x->right != NULL && y->left == NULL))
                return 0;

            if((x->left == NULL && y->right != NULL) || (x->left != NULL && y->right == NULL))
                return 0;
        }
        
        return l.size() == r.size();
    }
};