/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Edge case: An empty list or a single node with no cycle
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // Traverse the list
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Move slow pointer 1 step
            fast = fast->next->next;    // Move fast pointer 2 steps
            
            // If they meet, a cycle exists
            if (slow == fast) {
                return true;
            }
        }
        
        // If fast reaches the end, there is no cycle
        return false;
    }
};