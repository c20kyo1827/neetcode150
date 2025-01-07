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

/*
    If we know the root node, we can divide the tree into left tree and right tree from inorder
    1. root -> preorder[first]
    2. 
    Find the root idx of inorder -> because the preorder[first] must be the root and the value is unique
    Thus, we can use this to divide the inorder into the left tree and right tree
*/

// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         return buildTree(
//             preorder, 0, preorder.size()-1,
//             inorder,  0, inorder.size()-1
//             );
//     }
//     TreeNode* buildTree(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight) {
//         if(preLeft > preRight || inLeft > inRight) return nullptr;
//         int idxRoot;
//         for(idxRoot = inLeft ; idxRoot < inRight ; idxRoot++){
//             if(inorder[idxRoot] == preorder[preLeft]) break;
//         }
//         auto* cur = new TreeNode(preorder[preLeft]);
//         cur->left = buildTree(
//             preorder, preLeft+1, preLeft+1+(idxRoot-1-inLeft),
//             inorder, inLeft, idxRoot-1
//             );
//         cur->right = buildTree(
//             preorder, preLeft+1+(idxRoot-1-inLeft)+1, preRight,
//             inorder, idxRoot+1, inRight
//             );
//         return cur;
//     }
// };

// // with hashMap to prevent traverse inorder
// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         std::unordered_map<int, int> valToIdx;
//         for(int i=0 ; i<inorder.size() ; i++){
//             valToIdx[inorder[i]] = i;
//         }
//         return buildTree(
//             valToIdx,
//             preorder, 0, preorder.size()-1,
//             inorder,  0, inorder.size()-1
//             );
//     }

//     TreeNode* buildTree(std::unordered_map<int, int>& valToIdx, vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight) {
//         if(preLeft > preRight || inLeft > inRight) return nullptr;

//         auto* cur = new TreeNode(preorder[preLeft]);
//         int idxRoot = valToIdx[preorder[preLeft]];
//         cur->left = buildTree(
//             valToIdx,
//             preorder, preLeft+1, preLeft+1+(idxRoot-1-inLeft),
//             inorder, inLeft, idxRoot-1
//             );
//         cur->right = buildTree(
//             valToIdx,
//             preorder, preLeft+1+(idxRoot-1-inLeft)+1, preRight,
//             inorder, idxRoot+1, inRight
//             );
//         return cur;
//     }
// };

// // no hashMap
// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         return buildTree(
//             preorder, inorder, INT_MAX
//             );
//     }

//     int pre = 0, in = 0;
//     // stop : represent the root node of the sub-tree
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int stop) {
//         // touch the end of the preorder
//         if(pre >= preorder.size()) return nullptr;

//         // touch the stop point
//         if(inorder[in] == stop){
//             in++;
//             return nullptr;
//         }

//         auto* cur = new TreeNode(preorder[pre++]);
//         cur->left = buildTree(
//             preorder,  inorder, preorder[pre-1]
//             );
//         cur->right = buildTree(
//             preorder,  inorder, stop
//             );
//         return cur;
//     }
// };
/*
    1. cur->val = 3
        cur->left : stop=3
        cur->right : stop=MAX_INT
*/


// non-recursive
/*
          3 
        /  \
       9    7
     /  \
    20  15

    preorder = [3,  9, 20, 15, 7]
    inorder  = [20, 9, 15, 3,  7]

    1. root = 3 => how about the 9, left or right? => use the inorder to check
        if the 9 is on the right, the 9 should be on the right of 3 in the inorder => Thus, the 9 is on the left of 3
        if the 20 is on the right, the 20 should be on the right of 9 in the inorder => Thus, the 20 is on the left of 9
    2. how about 15?
        a. the right tree of 3 , the inorder : 20,9,3,15
        b. the right tree of 9 , the inorder : 20,9,15
        c. the right tree of 20, the inorder : 20,15
        
        if we check the reverse of traversed root [3,9,20] => [20,9,3]
            a. 20,9,3,15 <-> 20,9,3 => 15 is the right of 3
            b. 20,9,15   <-> 20,9   => 15 is the right of 9
            c. 20,15     <-> 20     => 20 is the right of 15
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        std::stack<TreeNode*> stackNode;
        int pre = 0, in = 0;
        auto* cur = new TreeNode(preorder[pre]);
        auto* root = cur;
        stackNode.push(cur);
        pre++;

        while(pre < preorder.size()){
            if(cur->val == inorder[in]){
                // Check when the traversed root == inorder[in]
                while(!stackNode.empty() && stackNode.top()->val == inorder[in]){
                    cur = stackNode.top();
                    stackNode.pop();
                    in++;
                }
                
                cur->right = new TreeNode(preorder[pre]);
                cur = cur->right;
                stackNode.push(cur);
                pre++;
            }
            else{
                cur->left = new TreeNode(preorder[pre]);
                cur = cur->left;
                stackNode.push(cur);
                pre++;
            }
        }
        return root;
    }
};
