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
        ostringstream code;
        serialize(root, code);
        return code.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(TreeNode* node, ostringstream& code){
        if(node != nullptr){
            code << node->val << ' ';
            serialize(node->left, code);
            serialize(node->right, code);
        }
        else{
            code << "- ";
        }
    }

    TreeNode* deserialize(istringstream &in){
        string token;
        in >> token;
        if(token == "-"){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(token));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
