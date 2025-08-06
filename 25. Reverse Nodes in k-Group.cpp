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
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         auto* dummy = new ListNode(-1, head);
//         auto* pre = dummy;
//         auto* node = head;
//         int cnt = 0;
//         while(node != nullptr){
//             cnt++;
//             auto* next = node->next;
//             if(cnt == k) {
//                 auto* newLast = pre->next;
//                 reverseOneGroup(pre, node);
//                 cnt = 0;
//                 pre = newLast;
//             }
//             node = next;
//         }
//         return dummy->next;
//     }

//     /*
//         if k = 3
//         pre -> node 1 -> node 2 -> node 3(last) -> ...
//     */
//     void reverseOneGroup(ListNode* pre, ListNode* last){
//         std::stack<ListNode*> s;
//         auto* cur = pre->next;
//         auto* lastNext = last->next;
//         while(cur != last->next){
//             s.push(cur);
//             cur = cur->next;
//         }
//         while(!s.empty()){
//             pre->next = s.top();
//             pre = s.top();
//             s.pop();
//         }
//         pre->next = lastNext;
//     }
// };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto* dummy = new ListNode(-1, head);
        auto* pre = dummy;
        auto* cur = dummy;
        int num = 0;
        while (cur = cur->next)
            ++num;
        while (num >= k) {
            cur = pre->next;
            for (int i = 1; i < k; ++i) {
                ListNode *t = cur->next;
                cur->next = t->next;
                t->next = pre->next;
                pre->next = t;
            }
            pre = cur;
            num -= k;
        }
        return dummy->next;
    }
};
