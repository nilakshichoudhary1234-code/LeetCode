class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;

        // check if there are at least k nodes
        while (curr != NULL && count < k) {
            curr = curr->next;
            count++;
        }

        if (count == k) {
            curr = reverseKGroup(curr, k);  // reverse rest
            
            while (count--) {
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
            }
            head = curr;
        }

        return head;
    }
};