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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root!=nullptr) q.push(root);
        while(!q.empty()){
            vector<int> _levels;
            auto size = q.size();
            for(int i=0 ; i<size ; i++){
                auto* frontNode = q.front();
                q.pop();
                _levels.push_back(frontNode->val);
                if(frontNode->left!=nullptr) q.push(frontNode->left);
                if(frontNode->right!=nullptr) q.push(frontNode->right);
            }
            ans.push_back(_levels);
        }
        return ans;
    }
};
