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
// Use a variable to record the level
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         int level = -1;
//         std::vector<int> ans;

//         std::stack< std::pair<int,TreeNode*> > s;
//         if(root != nullptr)
//             s.push({0,root});

//         while(!s.empty()){
//             auto val = s.top();
//             s.pop();
//             if(level < val.first){
//                 ans.push_back(val.second->val);
//                 level++;
//             }        
//             if(val.second->left != nullptr)
//                 s.push(std::make_pair(val.first+1, val.second->left));
//             if(val.second->right != nullptr)
//                 s.push(std::make_pair(val.first+1, val.second->right));
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         std::vector<int> ans;
//         std::queue<TreeNode*> q;
//         if(root == nullptr) return ans;
//         q.push(root);
//         while(!q.empty()){
//             ans.push_back(q.back()->val);
//             int size = q.size();
//             for(int i=0 ; i<size ; i++){
//                 if(q.front()->left != nullptr) q.push(q.front()->left);
//                 if(q.front()->right != nullptr) q.push(q.front()->right);
//                 q.pop();
//             }
//         }
//         return ans;
//     }
// };

class Solution {
    std::vector<int> ans;
public:
    vector<int> rightSideView(TreeNode* root) {
        checkLevel(root, 0);
        return ans;
    }

    void checkLevel(TreeNode *node, int level) {
        if(node == nullptr) return;
        if(ans.size() == level) ans.push_back(node->val);
        checkLevel(node->right, level+1);
        checkLevel(node->left, level+1);
    }
};
