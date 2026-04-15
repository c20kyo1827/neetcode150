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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto* cur = root;
        auto* left = p->val < q->val ? p : q;
        auto* right = p->val > q->val ? p : q;
        while(1){
            if(cur->val > right->val){
                cur = cur->left;
            }
            else if(cur->val < left->val){
                cur = cur->right;
            }
            else if(cur->val >= left->val && cur->val <= right->val){
                return cur;
            }
        }
    }
};
