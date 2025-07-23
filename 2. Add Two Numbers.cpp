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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto* longNode = getLength(l1) > getLength(l2) ? l1 : l2;
        auto* shortNode = getLength(l1) > getLength(l2) ? l2 : l1;
        auto* res = longNode;
        int carry = 0;
        while(longNode != nullptr) {
            if(shortNode != nullptr) {
                longNode->val += shortNode->val;
                shortNode = shortNode->next;
            }
            longNode->val += carry;
            carry = longNode->val >= 10 ? 1 : 0;
            longNode->val %= 10;
            if(carry == 1 && longNode->next == nullptr) {
                ListNode* node = new ListNode(0);
                longNode->next = node;
            }
            longNode = longNode->next;
        }
        return res;
    }
    int getLength(ListNode* cur) {
        int size = 0;
        while(cur != nullptr) {
            size++;
            cur = cur->next;
        }
        return size;
    }
};
