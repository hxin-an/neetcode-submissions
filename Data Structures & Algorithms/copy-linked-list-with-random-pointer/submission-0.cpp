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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        unordered_map < Node*, Node*> mp;
        Node * cp_head = new Node(0);
        Node *tail = head,* cp_tail = cp_head;

        // 複製 next 指標
        while(tail != nullptr){
            cp_tail->next = new Node(tail->val);
            cp_tail = cp_tail->next;
            mp[tail] = cp_tail;
            tail = tail->next;
        }

        // 複製 random 指標
        tail = head;
        cp_tail = cp_head->next;
        while (tail != nullptr){
            if (tail->random != nullptr)
               cp_tail->random = mp[tail->random];
            tail = tail->next;
            cp_tail = cp_tail->next;
        }
        


        return cp_head->next;
    }
};

// 複製一個 多一個指標的 linked list

