/*
    Runtime: 48 ms
    Memory Usage: 35.4 MB
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
    string serialize(TreeNode* root) {
        if(!root)
            return "# ";
        return to_string(root->val) + " " + serialize(root->left) + " "+ serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
    
private:
    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;

        if (val == "#")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        
        root->left = deserialize(in);
        root->right = deserialize(in);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));