/*
    Runtime: 12 ms
    Memory Usage: 17.5 MB
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
    TreeNode* build(vector<int>& postorder, int st, int en, int *pos, unordered_map<int, int>& mp) {
        if(st > en)
            return NULL;
        
        int val = postorder[*pos];
        TreeNode *node = new TreeNode(val);

        --(*pos);
        
        if(st == en)
            return node;
        
        int in = mp[val];
        
        node->right = build(postorder, in+1, en, pos, mp);
        node->left = build(postorder, st, in-1, pos, mp);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; ++i)
            mp[ inorder[i] ] = i;
        
        --n;
        return build(postorder, 0, n, &n, mp);
    }
};