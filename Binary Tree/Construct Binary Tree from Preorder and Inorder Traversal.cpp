/*
    Runtime: 16 ms
    Memory Usage: 17.4 MB
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
    TreeNode* build(vector<int>& preorder, int st, int en, int *pos, unordered_map<int, int>& mp)
    {
        if(st > en)
            return NULL;
        
        int val = preorder[*pos];
        TreeNode *node = new TreeNode(val);

        ++(*pos);
        
        if(st == en)
            return node;
        
        int in = mp[val];
        
        node->left = build(preorder, st, in-1, pos, mp);
        node->right = build(preorder, in+1, en, pos, mp);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size(), st = 0;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; ++i)
            mp[ inorder[i] ] = i;
        
        return build(preorder, 0, n-1, &st, mp);
    }
};