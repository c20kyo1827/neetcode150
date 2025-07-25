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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1, head);
        auto* pre = dummy;
        auto* cur = pre->next;
        while(cur != nullptr){
            if(cur->val == val){
                pre->next = cur->next;
                cur->next = nullptr;
                delete cur;
                cur = pre->next;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
