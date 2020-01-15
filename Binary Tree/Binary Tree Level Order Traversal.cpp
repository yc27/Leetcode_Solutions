/*
    Runtime: 8 ms
    Memory Usage: 13.7 MB
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        
        if(root)
            q.push(root);
        
        int len = q.size();
        
        while(len > 0) {

            vector<int> v;

            for(int i = 0; i < len; ++i) {
                root = q.front();
                q.pop();

                v.push_back(root->val);

                if(root->left)
                    q.push(root->left);

                if(root->right)
                    q.push(root->right);
            }

            len = q.size();
            ret.push_back(v);
        }

        return ret;
    }
};