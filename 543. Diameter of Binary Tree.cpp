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
// class Solution {
//     int res = 0;
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         res = 0;
//         getMaxCount(root);
//         return res;
//     }
//     int getMaxCount(TreeNode* node) {
//         if(node == nullptr) return 0;

//         // TLE --> store the value
//         // res = std::max(res, getMaxCount(node->left) + getMaxCount(node->right) + 1);
//         // return std::max(getMaxCount(node->left)+1, getMaxCount(node->right)+1);

//         // store the value
//         int left = getMaxCount(node->left);
//         int right = getMaxCount(node->right);
//         res = std::max(res, left+right);
//         return std::max(left, right)+1;
//     }
// };

class Solution {
    unordered_map<TreeNode*, int> nodeToCount;
    int res = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        getMaxCount(root);
        return res;
    }
    int getMaxCount(TreeNode* node) {
        if(node == nullptr) return 0;
        if(nodeToCount.count(node)) return nodeToCount[node];
        int left = getMaxCount(node->left);
        int right = getMaxCount(node->right);
        res = std::max(res, left+right);
        nodeToCount[node] = std::max(left, right)+1;
        return nodeToCount[node];
    }
};
