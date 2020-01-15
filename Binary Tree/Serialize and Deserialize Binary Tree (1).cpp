/*
	Runtime: 28 ms
	Memory Usage: 22 MB
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
class Codec {
public:
    
    // Encodes a tree to a single string.
    TreeNode* serialize(TreeNode* root) {
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(TreeNode* root) {
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));