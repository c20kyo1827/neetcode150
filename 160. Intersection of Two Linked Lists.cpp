/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// // Space : O(N)
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         std::set<ListNode *> visited;
//         while(headA != nullptr){
//             visited.insert(headA);
//             headA = headA->next;
//         }

//         while(headB != nullptr){
//             if(visited.count(headB))
//                 return headB;
//             headB = headB->next;
//         }
//         return 0;
//     }
// };

// Space : O(1)

// Two pointer
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==nullptr || headB==nullptr) return nullptr;
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        int diff = std::abs(lenA - lenB);
        if (lenA > lenB) {
            while(diff-- > 0){
                headA = headA->next;
            }
        }
        else{
            while(diff-- > 0){
                headB = headB->next;
            }
        }
        while(headA != nullptr){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
private:
    int getLength(ListNode* head) {
        int length = 0;
        while(head != nullptr){
            length++;
            head = head->next;
        }
        return length;
    }
};

// 
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode *cur1 = headA, *cur2 = headB;
//         while(cur1 != cur2){
//             cur1 = cur1?cur1->next:headB;
//             cur2 = cur2?cur2->next:headA;
//         }
//         return cur1;
//     }
// };
