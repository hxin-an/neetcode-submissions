class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        // 1. 找到前半段的尾端
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. 真正切成兩條 Linked List
        ListNode* sec_head = slow->next;
        slow->next = nullptr;

        // 3. 反轉後半段
        ListNode* prev = nullptr;

        while (sec_head != nullptr) {
            ListNode* next = sec_head->next;
            sec_head->next = prev;
            prev = sec_head;
            sec_head = next;
        }

        sec_head = prev;

        // 4. 交錯合併
        while (sec_head != nullptr) {
            ListNode* firstNext = head->next;
            ListNode* secondNext = sec_head->next;

            head->next = sec_head;
            sec_head->next = firstNext;

            head = firstNext;
            sec_head = secondNext;
        }
    }
};