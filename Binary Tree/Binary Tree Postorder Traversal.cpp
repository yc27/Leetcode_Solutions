/*
    Runtime: 0 ms
    Memory Usage: 9 MB
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        
        stack<TreeNode*> s;
        
        while(root || !s.empty()){            
            while(root){
                s.push(root);
                ret.insert(ret.begin(), root->val);
                root = root->right;
            }
            
            root = s.top();
            s.pop();
            root = root->left;
        }
        
        return ret;        
    }
};