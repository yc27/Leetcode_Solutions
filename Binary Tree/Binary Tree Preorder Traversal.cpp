/*
	Runtime: 0 ms
	Memory Usage: 9.1 MB
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> stk;
        TreeNode* node;
        
        stk.push(root);
        while(!stk.empty()) {
            node = stk.top();
            stk.pop();

            if(node == NULL)
                continue;

            v.push_back(node->val);

            if(node->right != NULL)
                stk.push(node->right);
            
            if(node->left != NULL)
                stk.push(node->left);
        }
        return v;
    }
};