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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // 1. Compute the length and find the actual tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // 2. Handle cases where k >= length
        k = k % length;
        if (k == 0) return head;

        // 3. Connect tail to head to form a cycle
        tail->next = head;

        // 4. Find the new tail: (length - k - 1) steps from head
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }

        // 5. Break the cycle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;

        
    }
};