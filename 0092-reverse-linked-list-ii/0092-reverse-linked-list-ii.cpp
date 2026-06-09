/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(x) : val(x), next(nullptr) {}
 * ListNode(x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Dummy node handles cases where left = 1 seamlessly
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Step 1: Move prev to the node right before the sub-list to be reversed
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        // curr points to the first node of the sub-list to be reversed
        ListNode* curr = prev->next; 

        // Step 2: Reverse the sub-list in place
        for (int i = 0; i < right - left; ++i) {
            ListNode* nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }

        ListNode* result = dummy->next;
        delete dummy; // Free the allocated dummy node
        return result;
    }
};