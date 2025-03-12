/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans = 0;
public:
    int goodNodes(TreeNode* root) {
        traverseNode(root, root->val);
        return ans;
    }

    void traverseNode(TreeNode* node, int maxValue){
        if(node == nullptr) return;
        if(node->val >= maxValue) ans++;
        traverseNode(node->right, std::max(node->val, maxValue));
        traverseNode(node->left, std::max(node->val, maxValue));
    }
};
