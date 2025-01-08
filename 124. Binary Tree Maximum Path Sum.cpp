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
public:
    int pathRes = INT_MIN;
    int maxPathSum(TreeNode* root) {
        findPathSum(root);
        return pathRes;
    }

    int findPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftIncr = std::max(findPathSum(root->left), 0);
        int rightIncr = std::max(findPathSum(root->right), 0);
        pathRes = std::max(pathRes, root->val+leftIncr+rightIncr);
        return std::max(root->val+leftIncr, root->val+rightIncr);
    }
};
