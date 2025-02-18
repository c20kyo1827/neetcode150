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
    bool isBalance;
public:
    int isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        isBalance = true;
        int left = getMaxCount(root->left);
        int right = getMaxCount(root->right);
        isBalance &= std::abs(left-right) <= 1;
        return isBalance;
    }
    int getMaxCount(TreeNode* node) {
        if(node == nullptr) return 0;
        int left = getMaxCount(node->left);
        int right = getMaxCount(node->right);
        isBalance &= std::abs(left-right) <= 1;
        return std::max(left, right)+1;
    }
};
