/*
    Runtime: 8 ms
    Memory Usage: 14.8 MB
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
    bool isMirror(TreeNode* l, TreeNode* r) {
        if(l == NULL && r == NULL)
            return 1;
        
        if(l == NULL || r == NULL)
            return 0;
        
        if(l->val != r->val)
            return 0;
        
        return (isMirror(l->right, r->left) & isMirror(l->left, r->right));
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return 1;
        
        return isMirror(root->left, root->right);
    }
};