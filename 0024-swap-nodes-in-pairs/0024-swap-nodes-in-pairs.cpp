/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // If the list is empty or has only one node, no swaps are possible
        if (!head || !head->next) {
            return head;
        }

        // Dummy node to point to the new head of the list
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            // Nodes to be swapped
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swapping logic
            // 1. Point prev to the second node
            // 2. Point first node to whatever was after second
            // 3. Point second node back to first
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move the prev pointer two nodes ahead for the next pair
            prev = first;
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return newHead;
    }
};