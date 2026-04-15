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

// Recursive
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, static_cast<long>(-2147483649), static_cast<long>(2147483648));
    }
    bool isValidBST(TreeNode* root, long min, long max){
        if(!root) return true;
        if(root->val <= min || root->val >= max) return false;
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
};

// // Inorder
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         if(!root) return true;
//         vector<int> res;
//         inorder(root, res);
//         for (int i = 0; i < res.size() - 1; ++i) {
//             if (res[i] >= res[i+1]) return false;
//         }
//         return true;
//     }
//     void inorder(TreeNode* root, vector<int>& res){
//         if(!root) return;
//         inorder(root->left, res);
//         res.push_back(root->val);
//         inorder(root->right, res);
//     }
// };
