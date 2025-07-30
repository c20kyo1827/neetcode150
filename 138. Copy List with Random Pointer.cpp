/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// // # Hash map
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if(head == nullptr) return nullptr;
//         std::unordered_map<Node*, Node*> orig2new;
//         Node* cur = new Node(head->val);
//         cur->random = head->random;
//         orig2new[head] = cur;
//         head = head->next;
//         while(head != nullptr){
//             cur->next = new Node(head->val);
//             cur->next->random = head->random;
//             orig2new[head] = cur->next;

//             cur = cur->next;
//             head = head->next;
//         }
//         cur = start->next;
//         while(cur != nullptr){
//             cur->random = orig2new[cur->random];
//             cur = cur->next;
//         }
//         return orig2new[head];
//     }
// };

// # Hash map with recursive
class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> orig2new;
        return copyRandomList(head, orig2new);
    }

    Node* copyRandomList(Node* node, std::unordered_map<Node*, Node*>& orig2new){
        if(node == nullptr) return nullptr;
        if(orig2new.count(node)) return orig2new[node];
        Node* cur = new Node(node->val);
        orig2new[node] = cur;
        cur->next = copyRandomList(node->next, orig2new);
        cur->random = copyRandomList(node->random, orig2new);
        return cur;
    }
};

// No need hash
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if (!head) return nullptr;
//         Node *cur = head;
//         // orignal node's next -> new node
//         while(cur != nullptr) {
//             auto *node = new Node(cur->val);
//             node->next = cur->next;
//             cur->next = node;
//             cur = node->next;
//         }
//         // Random 
//         cur = head;
//         while(cur != nullptr) {
//             auto *node = cur->next;
//             if (cur->random != nullptr)
//                 node->random = cur->random->next;
//             cur = node->next;
//         }
//         // Next
//         cur = head;
//         Node *res = head->next;
//         while(cur != nullptr)  {
//             auto *node = cur->next;
//             cur->next = node->next;
//             if (node->next != nullptr)
//                 node->next = node->next->next;
//             cur = cur->next;
//         }
//         return res;
//     }
// };
