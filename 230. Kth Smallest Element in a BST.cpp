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
// Use the stack to find the smaller nodes and check the count
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         std::stack<TreeNode*> nodeStack;
//         int cnt = 0;
//         auto* cur = root;
//         while(cur!=nullptr || !nodeStack.empty()){
//             // Get all smaller nodes of cur node
//             while(cur != nullptr){
//                 nodeStack.push(cur);
//                 cur = cur->left;
//             }
//             cur = nodeStack.top();
//             nodeStack.pop();
//             cnt++;
//             if(cnt == k) return cur->val;
//             cur = cur->right;
//         }
//         return 0;
//     }
// };

// Find the count from the cur node
// If the kthSmallest is frequently called -> build the count initially
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = getCount(root->left);
        // cout << cnt << " " << root->val << "\n";
        if(cnt >= k){
            return kthSmallest(root->left, k);
        }
        else if(cnt+1 < k){
            return kthSmallest(root->right, k-cnt-1);
        }
        return root->val;
    }

    int getCount(TreeNode* root){
        if(root == nullptr) return 0;
        int cnt = 0;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto* cur = q.front();
            q.pop();
            cnt++;
            if(cur->left != nullptr) q.push(cur->left);
            if(cur->right != nullptr) q.push(cur->right);
        }
        return cnt;
    }
};
