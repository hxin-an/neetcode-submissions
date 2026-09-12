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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = 0, target, tmp = 1 ;
        ListNode *now = head, *prev = nullptr;

        while( now != nullptr){
            num++;
            now = now->next;
        }

        if(num == 1)
            return nullptr;

        target = num - n + 1;
        now = head;

        if ( target == 1)
            return head->next;

        while (now != nullptr){
            prev = now;
            now = now->next;
            tmp++;

            if( tmp == target){
                prev->next = now->next;
            }
        }

        return head;
    }
};
// 算 node 數量