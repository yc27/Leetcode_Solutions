/*
	Runtime: 4 ms
	Memory Usage: 9.2 MB
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> stk;
        TreeNode* node = root;

	    while(node != NULL || !stk.empty()) {
            while(node != NULL) {
                stk.push(node); 
                node = node->left; 
            } 

            node = stk.top(); 
            stk.pop(); 

            v.push_back(node->val);
            node = node->right;
        }
        return v;
        
    }
};