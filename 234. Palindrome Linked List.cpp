/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         ListNode *cur = head;
//         stack <int> s;
//         while (cur != nullptr){
//             s.push(cur->val);
//             cur = cur->next;
//         }
        
//         while (head != nullptr){
//             int a = s.top();
//             s.pop();
            
//             if (a != head->val) 
//                 return false;
//             head = head->next;
//         }
//         return true;
//     }
// };

// Recursion
/*
    Leverage the recursive function as the stack

    1 -> 2 -> 2 -> 1
    c,n

    1 -> 2 -> 2 -> 1
    c    n

    1 -> 2 -> 2 -> 1
    c         n

    1 -> 2 -> 2 -> 1
    c              n

    1. Check if node==cur
    2. move cur to the next
    3. Then, we will go back to the previsou recursive function
    4. Thus, we can compare the palindrome 

*/
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         auto* cur = head;
//         return check(head, cur);
//     }
//     bool check(ListNode* node, ListNode*& cur){
//         if(node == nullptr) return true;
//         // cout << "Start:" << node->val << " " << cur->val << "\n";
//         bool res = check(node->next, cur) && (cur->val == node->val);
//         // cout << "End:" << node->val << " " << cur->val << "\n";
//         cur = cur->next;
//         return res;
//     }
// };

// Two pointer
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->val << "\n";
        cout << fast->val << "\n";
        ListNode *last = slow->next, *pre = head;
        // Flip the half linked list
        // Start slow->next
        while (last->next) {
            ListNode *tmp = last->next;
            last->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        // Check
        while (slow->next) {
            slow = slow->next;
            if (pre->val != slow->val) return false;
            pre = pre->next;
        }
        return true;
    }
};
